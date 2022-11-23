#include <iostream>
#include "Stack.h"
using namespace std;

Node::Node()
{
    data = 0;
    next = NULL;
}

Node::Node(int x)
{
    data = x;
    next = NULL;
}

Stack::Stack(/* args */)
{
    top = NULL;
}

void Stack::push(int x)
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

void Stack::pop()
{
    Node *temp = top;
    top = top->next;
    delete temp;
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

Stack::~Stack()
{
    delete top;
}
