#include <iostream>
using namespace std;

void reverseArray(int *arr, int low, int high)
{
    while (low <= high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

void shiftLeftByN(int *arr, int n, int k)
{
    k = k % n; // for the case if k >= n
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
    reverseArray(arr, 0, n - 1);
}
int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    shiftLeftByN(A, 5, 2);
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
