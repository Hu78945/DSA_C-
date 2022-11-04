#include <iostream>
using namespace std;

int main()
{
    int A[5] = {1, 2, 3, 4};
    /* for (int i = 0; i < 5; i++)
    {
        cout << A[i] << endl;
    } */
    // Another method of accessing
    // cout << 2 [A] << endl;
    // using pointer arithmatic methode
    // cout << *(A + 3) << endl;
    // Adress of the all the location of array
    /*  for (int i = 0; i < 5; i++)
     {
         cout << &A[i] << endl;
     } */

    // Staic vs Dynamic Array
    int *P;
    // C++ way of creating array on heap
    P = new int[5];
    // C way of creating array on heap
    P = (int *)malloc(5 * sizeof(int));
    // Accessing elemt of the array
    P[0] = 5;
    P[1] = 25;
    P[2] = 57;
    P[3] = 59;
    P[4] = 54;
    // increase and decraese size of array only valid in heap
    int *q = new int[10];
    // Now copy the content of p to q;
    for (int i = 0; i < 5; i++)
    {
        q[i] = P[i];
    }
    // Delete the P Array
    delete[] P;
    // Now point p to q
    P = q;
    // Assign q to Null
    q = NULL;

    // Deleteing array from heap C++
    delete[] P;
    // Deleteing array from heap C
    free(P);

    // Multi Dimision Array
    // 2D Array
    // Ist Method
    int L[3][4] = {{1, 2, 3, 4}, {4, 5, 6, 8}, {7, 8, 9, 4}};
    // 2nd Method
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    // Accessing is the same
    B[0][2] = 15;

    // 3rd Methode using double pointer
    int **C;
    C = new int *[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    // Accessing using loops
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}