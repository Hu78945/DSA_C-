#include <iostream>
#include "Array.h"
using namespace std;

// Default Constructor
Array::Array(/* args */)
{
    // default size of 10 with zero elemet
    arr = new int[10];
    length = 10;
}

// Overloaded Constructor
Array::Array(int size)
{
    arr = new int[size];
    length = size;
}

Array::~Array()
{
    delete[] arr;
}

bool Array::SizeFull()
{
    int counter = 0;
    bool ToReturn;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] != 0)
            counter++;
    }
    (counter == length) ? ToReturn = true : ToReturn = false;
    return ToReturn;
}

void Array::ExtendSize()
{
    int *newArray = new int[length + 10];
    delete[] arr;
    arr = newArray;
    newArray = NULL;
    length += 10;
}

void Array::push(int element)
{
    if (arr[0] == 0)
    {
        arr[0] = element;
        size++;
    }
    else
    {
        if (!SizeFull())
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == 0)
                {
                    arr[i] = element;
                    size++;
                    break;
                }
            }
        }
        else
        {
            int tempSize = length;
            ExtendSize();
            arr[tempSize] = element;
            size++;
        }
    }
}

void Array::PrintArray()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
