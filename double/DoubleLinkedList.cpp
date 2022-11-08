#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

Node::Node()
{
    data = 0;
    next = NULL;
    prev = NULL;
}
Node::Node(int data)
{
    this->data = data;
    next = NULL;
    prev = NULL;
}

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
}

DoubleLinkedList::DoubleLinkedList(int data)
{
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    length = 1;
}

void DoubleLinkedList::append(int data)
{
    Node *newNode = new Node(data);
    if (head && tail)
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        length++;
    }
    else
    {
        head = newNode;
        tail = newNode;
        length = 1;
    }
}

void DoubleLinkedList::Display()
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void DoubleLinkedList::Insert(int index, int data)
{
    if (index < 0 || index >= length)
    {
        cout << "Please enter a valid index" << endl;
    }
    else
    {
        Node *prevNode = TraverseToIndex(index - 1);
        Node *newNode = new Node(data);
        newNode->prev = prevNode;
        newNode->next = prevNode->next;
        if (prevNode->next)
        {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        length++;
    }
}

Node *DoubleLinkedList::TraverseToIndex(int index)
{
    Node *p = head;
    int counter = 0;
    while (counter != index)
    {
        p = p->next;
        counter++;
    }
    return p;
}

void DoubleLinkedList::Delete()
{
    Node *newTail = tail->prev;
    Node *prevTail = tail;
    newTail->next = NULL;
    tail = newTail;
    delete prevTail;
}

void DoubleLinkedList::DeleteAtIndex(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Please enter a valid index" << endl;
    }
    else
    {
        Node *prevNode = TraverseToIndex(index - 1);
        Node *dNode = prevNode->next;
        Node *newNext = prevNode->next->next;
        if (newNext != NULL)
        {
            newNext->prev = prevNode;
        }
        prevNode->next = newNext;
        length--;
        delete dNode;
    }
}

void DoubleLinkedList::Reverse()
{
    Node *p = head;
    while (p)
    {
        Node *temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
    }
    Node *temp = head;
    head = tail;
    tail = head;
}

DoubleLinkedList::~DoubleLinkedList()
{
    delete head;
    delete tail;
}
