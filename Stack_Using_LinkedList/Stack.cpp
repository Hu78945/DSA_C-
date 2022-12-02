#include <iostream>
#include "Stack.h"
using namespace std;

Node::Node()
{
    data = 0;
    next = NULL;
}

Node::Node(char x)
{
    data = x;
    next = NULL;
}

Stack::Stack(/* args */)
{
    top = NULL;
}

void Stack::push(char x)
{
    if (top == NULL)
    {
        top = new Node(x);
    }
    else
    {
        Node *temp = top;
        Node *newTop = new Node(x);
        if (newTop == NULL)
        {
            cout << "Stack OverFlow" << endl;
        }
        else
        {
            newTop->next = top;
            top = newTop;
        }
    }
}

char Stack::pop()
{
    Node *temp = top;
    top = top->next;
    return temp->data;
}

int Stack::IsEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack::IsFull()
{
    Node *t = new Node();
    if (t == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Stack::Display()
{
    Node *p = top;
    while (top != NULL)
    {
        cout << p->data << "\n";
        p = p->next;
    }
}

char Stack::stackTop()
{
    return top->data;
}

Stack::~Stack()
{
    delete top;
}
