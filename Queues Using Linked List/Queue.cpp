#include <iostream>
#include "Queue.h"
using namespace std;

Node::Node()
{
    data = 0;
    next = NULL;
}

Node::Node(int data)
{
    this->data = data;
    next = NULL;
}

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

void Queue::enqueu(int data)
{
    Node *newNode = new Node(data);
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void Queue::dequeu()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue::isFull()
{
    Node *t = new Node();
    if (t == NULL)
    {
        cout << "Queue is Full" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::Display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
