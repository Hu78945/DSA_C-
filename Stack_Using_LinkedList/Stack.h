#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node();
    Node(char x);
};

class Stack
{
private:
    Node *top;

public:
    Stack();
    void push(char x);
    char stackTop();
    char pop();
    int IsEmpty();
    int IsFull();
    void Display();

    ~Stack();
};
