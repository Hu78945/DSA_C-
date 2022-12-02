#include <iostream>
#include "Queues.h"
using namespace std;

Queue::Queue()
{
    size = 6;
    front = 0;
    rear = 0;
    A = new int[size];
}

Queue::Queue(int size)
{
    this->size = size;
    front = 0;
    rear = 0;
    A = new int[size];
}

void Queue::enqueue(int item)
{
    if (rear + 1 % size == front)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        rear = rear + 1 % size;
        A[rear] = item;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        front = front + 1 % size;
        x = A[front];
    }
    return x;
}

bool Queue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::Display()
{
    int i = front + 1;
    do
    {
        printf("%d ", A[i]);
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    printf("\n");
}
