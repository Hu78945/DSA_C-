#include <iostream>
#include "Sorting.h"
using namespace std;

void BubbleSort(int A[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void InsertionSort(int A[], int n)
{
    if (A[n - 1] != 0)
    {
    }
}

void PrintArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}