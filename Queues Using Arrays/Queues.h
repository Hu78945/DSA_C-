#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *A;

public:
    Queue();
    Queue(int size);
    void enqueue(int item);
    int dequeue();
    bool isFull();
    bool isEmpty();
    void Display();
};