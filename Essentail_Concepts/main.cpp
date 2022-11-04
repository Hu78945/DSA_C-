#include <iostream>
using namespace std;

// Structure are related data memeber may be of similar type
// Collection of differnet data item under one name
// Use for defining user defined data type
struct Rectangle
{
    int length;  //------> 4Bytes
    int breadth; // ------> 4bytes
};
// Right now it is not taking any memory cause its a defination but if we make a variable
// then it will take space.

// Card Strcutrure
struct Card
{
    int face;
    int shape;
    int color;
};

// Functions
/*
    In c language we only have pass by value and pas by adress but in c++ we also have pass by reference in paramter passing.
 */

// Parmeter passing methods

// Pass By Value / Call by value
void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Pass By address / Call by address
void swap1(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Pass By reference / Call by reference
void swap2(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Array as a parameter
void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

// Return array as ouput from the function
int *fun12(int n)
{
    int *p;
    p = new int[n];
    return p;
}

// Structure
// You can pass structure as call by value even if it hve a array it will make a copy of the array

struct Test
{
    int arr[5];
    int n;
};

void func(struct Test t)
{
    t.arr[0] = 1;
    t.n = 20;
    // Changes will not change acutal parameter cause it is call by value ony formal parameter will be changed
}

int main()
{
    // declartion
    int A[5];
    // declartion and initlization
    int B[5] = {1, 2, 3, 4, 5};

    // Structure
    // Declartion
    struct Rectangle r;
    // This will occupy 8bytes first 4 for length and other 4 for breadth
    // declartion and initlization
    struct Rectangle r1 = {10, 5};
    // Its is created inside the stack in the main memory.
    // accesing data members
    r1.length = 15;
    r1.breadth = 10;
    cout << "Area of the rectangle is " << r.length * r.breadth << endl;

    // Array of structure
    struct Card deck[52];

    // Pointer

    /*
        Pointer is an adress variable that is meeant for storing the adrres of the data.
        Pointers are used for indirectly accessing the data.
        Programe can directly acces stack and code section of main memory. It can not directly access the heap section. Heap memoory is external to programe for that it needs a pointer.

        For Example :
        If we wannt to acces the files on hard drive we can not do so using typical way causes its in secondayr memory we will use pointer of type file to point ot that data.
        Accessing the resources which are outside the programe.
        Pointer are use for parmemter passing.
     */

    int a = 10;         // -----> will be created in the stack fo the memory
    int *p;             // -----> will also be created inside the stack.
    p = &a;             // will heave addrss of a and it will be pointing to the a.
    cout << a;          // it will give value of a
    cout << *p << endl; // will display the value of a through pointer also called derefercing.

    // Accessing heap memory using a pointer.
    int *p1;
    // You can only use heap by using malloc;
    // p1 = (int *)malloc(5 * sizeof(int)); // ---> will declare the memory for five integer.
    // malloc returns a void pointer so we have to type cast it to int pointer.
    // The newer c++ syntax
    p1 = new int[5];
    p1[0] = 10;
    p1[1] = 2;
    p1[2] = 9;
    p1[3] = 4;
    p1[4] = 5;
    cout << *(p1 + 2) << endl;

    // Reference in c++
    /*
        Referencec is only available in c++ it is not a part of c language . It is a nick name or alisa given to a variable
     */
    int c = 10;
    int &t = c; // if there is an & betwnn type and variable name it is reference must be init when declared. The above expression means that a it selfe is called t. It is haveing one more name t. Two  names for the same valued inside the memory. It is usefull in parameter passing.

    // Pointer upon a structure
    // Pointer always takes space equal to a int in any compiler
    struct Rectangle *rp = &r1;
    // The old C way
    (*rp).length = 20;
    // New way in c++
    rp->length = 20;

    // Create an object dynamically on the heap
    struct Rectangle *cp;
    // Old way in C
    cp = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    // New c++ way
    cp = new struct Rectangle;
    cp->length = 10;
    cp->breadth = 5;

    // Functions Example

    // Pass by Vlaue
    int a1, b;
    a1 = 10;
    b = 20;
    swap(a1, b);
    cout << a << " " << b << endl;

    // Pass by adress
    swap1(&a1, &b);
    cout << a << " hmmm " << b << endl;

    // pass by reference
    swap2(a1, b);
    cout << a << " " << b << endl;

    // Array passing as parameter
    int arr[5] = {1, 2, 3, 4, 5};
    print(arr, 5);

    // get arrays as output from the function
    int *u;
    u = fun12(5);

    // Structure as parameter
    struct Test t1 = {{1, 2, 3, 4, 5}, 10};

    return 0;
}