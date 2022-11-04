#include <iostream>
#include "LowerTriangularMatrix.h"
using namespace std;

LowerTriangularMatrix::LowerTriangularMatrix(int size)
{
    n = size;
    A = new int[(n * (n + 1) / 2)];
}

LowerTriangularMatrix::~LowerTriangularMatrix()
{
    delete[] A;
}

void LowerTriangularMatrix::set(int i, int j, int x)
{
    if (i >= j)
    {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int LowerTriangularMatrix::get(int i, int j)
{
    if (i >= j)
    {
        return A[(i * (i - 1) / 2) + j - 1];
    }
    return -1;
}

void LowerTriangularMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
