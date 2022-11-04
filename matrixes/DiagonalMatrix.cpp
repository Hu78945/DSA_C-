#include <iostream>
#include "DiagonalMatrix.h"
using namespace std;

DiagonalMatrix::DiagonalMatrix(int size)
{
    n = size;
    A = new int[n];
}

DiagonalMatrix::~DiagonalMatrix()
{
    delete[] A;
}

// to set the diagonal entries of the matrix
void DiagonalMatrix::set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}

// to get the diagonal entries of the matrix
int DiagonalMatrix::get(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    else
    {
        return 0;
    }
}

// Dispay the matrix

void DiagonalMatrix::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
