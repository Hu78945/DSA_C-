#include <iostream>
#include <cmath>

using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array(int size);
    void FillArray();
    void Display();
    void Add(int ele);
    void Insert(int index, int ele);
    int Delete(int index);
    int Search(int key);
    void Swap(int i, int j);
    int BinarySearch(int key);
    int RecursiveBinarySearch(int low, int high, int key);
    int Get(int index);
    void Set(int index, int ele);
    int Max();
    int Min();
    int Sum();
    int Avg();
    void Reverse();
    void LeftShift();
    void Inset(int ele);
    bool isSorted();
    void NegativeOnLeft();
    static Array Union(Array a1, Array a2)
    {
        int k = 0;
        Array a3 = {a1.length + a2.length};
        for (int i = 0; i < a1.length; i++)
        {
            if (!(a3.A[i] == a1.A[i]))
            {
                a3.A[i] = a1.A[i];
                a3.length++;
                k++;
            }
        }

        for (int i = 0; i < a2.length; i++)
        {
            if (!(a3.A[i] == a2.A[i]))
            {
                a3.A[k] = a2.A[i];
                k++;
                a3.length++;
            }
        }
        return a3;
    }
};

// OverLoaded Constructor

Array::Array(int size)
{
    this->size = size;
    A = new int[size];
    length = 0;
}

// Fill Array
void Array::FillArray()
{
    int n;
    cout << "Enter the numbers you want to enter " << endl;
    cin >> n;
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        length++;
    }
}

// Display Function
void Array::Display()
{
    cout << "[ ";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " "
             << ","
             << " ";
    }
    cout << "]" << endl;
    cout << "Length of Array: " << length << endl;
    cout << "Size of Array: " << size << endl;
}

void Array::Add(int ele)
{
    if (length != size)
    {
        A[length] = ele;
        length++;
    }
    else
    {
        int *B = new int[size + 10];
        for (int i = 0; i < length; i++)
        {
            B[i] = A[i];
        }
        delete[] A;
        A = B;
        B = NULL;
        A[length] = ele;
        size += 10;
        length++;
    }
}

void Array::Insert(int index, int ele)
{
    if (index < length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = ele;
        length++;
    }
}

int Array::Delete(int index)
{
    int x = A[index];
    for (int i = index; i < length - 1; i++)
    {
        A[i] = A[i + 1];
    }
    length--;
    return x;
}

int Array::Search(int key)
{
    // We can increase the linear search by transpostion methode
    // By moving that key one step closer
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            int temp = A[i - 1];
            A[i - 1] = A[i];
            A[i] = temp;
            return i - 1;
        }
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    // needs to be sorted first
    int low = 0;
    int high = length - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = floor((low + high) / 2);
        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int Array::RecursiveBinarySearch(int low, int high, int key)
{
    // needs to be sorted first
    int mid;
    while (low <= high)
    {
        mid = floor((low + high) / 2);
        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            return RecursiveBinarySearch(low, mid - 1, key);
        }
        else
        {
            return RecursiveBinarySearch(mid + 1, high, key);
        }
    }
    return -1;
}

int Array::Get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int ele)
{
    if (index >= 0 && index < length)
    {
        A[index] = ele;
    }
}

int Array::Max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int Array::Min()
{
    int min = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

int Array::Sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }

    return sum;
}

int Array::Avg()
{
    int total = Sum();
    return total / length;
}

void Array::Reverse()
{
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }
}

void Array::LeftShift()
{
    for (int i = 0; i < length; i++)
    {
        A[i] = A[i + 1];
    }
}

void Array::Inset(int ele)
{
    int i = length - 1;
    while (A[i] > ele)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = ele;
    length++;
}

bool Array::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return false;
        }
    }
    return true;
}

void Array::NegativeOnLeft()
{
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[i] > 0)
            j--;

        swap(A[i], A[j]);
    }
}

// static Array Array::Union(Array a1, Array a2)
// {
// }

int main()
{
    Array A1 = {4};
    A1.Add(10);
    A1.Add(20);
    A1.Add(40);
    A1.Add(50);

    Array A2 = {5};
    A2.Add(60);
    A2.Add(70);
    A2.Add(80);
    A2.Add(90);
    A2.Add(90);

    Array A3 = Array::Union(A1, A2);
    A3.Display();

    return 0;
}