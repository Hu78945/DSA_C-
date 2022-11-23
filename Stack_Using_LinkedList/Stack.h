#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node();
    Node(int x);
};

class Stack
{
private:
    Node *top;

public:
    Stack();
    void push(int x);
    void pop();
    int IsEmpty();
    int IsFull();
    void Display();

    ~Stack();
};
