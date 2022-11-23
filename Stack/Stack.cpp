#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack()
{
    size = 5;
    top = -1;
}

Stack::Stack(char size)
{
    this->size = size;
    top = -1;
}

void Stack::Push(char x)
{
    if (top == size - 1)
    {
        cout << "Stack OverFlow" << endl;
    }
    else
    {
        top++;
        Arr[top] = x;
    }
}

int Stack::Pop()
{
    int x = -1;
    if (top == -1)
    {
        cout << "Stack UnderFlow \n";
    }
    else
    {
        Arr[top];
        top--;
    }
    return x;
}

int Stack::Peek(int pos)
{
    int x = -1;
    if (top - pos + 1 < 0 || top - pos + 1 > size)
    {
        cout << "Invalid Postion" << endl;
    }
    else
    {
        x = Arr[top - pos + 1];
    }
    return x;
}

int Stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack::StackTop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return Arr[top];
    }
}

void Stack::Display()
{
    for (int i = 0; i <= top; i++)
    {
        cout << Arr[i] << "\n";
    }
}

Stack::~Stack()
{
    delete Arr;
}
