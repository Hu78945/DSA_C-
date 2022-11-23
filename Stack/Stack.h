#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    char *Arr = new char[size];

public:
    Stack();
    Stack(char size);
    void Push(char x);
    int Pop();
    int Peek(int pos);
    int isEmpty();
    int isFull();
    int StackTop();
    void Display();
    ~Stack();
};
