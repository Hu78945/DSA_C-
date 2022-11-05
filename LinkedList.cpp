#include <iostream>
#include "LinkedList.h"
using namespace std;

// Constructor
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

Node::Node(int data, Node *next)
{
    this->data = data;
    this->next = next;
}

// Getter / Setter function
Node *Node::getNext()
{
    return next;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

int Node::getData()
{
    return data;
}

// Linked List Constructor
LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

LinkedList::LinkedList(Node *item)
{
    head = item;
    tail = item;
    length++;
}

// Linked List Destructor
LinkedList::~LinkedList()
{
    delete head;
    delete tail;
}

// Get the head of the linked list
Node *LinkedList::GetHead()
{
    return this->head;
}

// Add or Append Methode
void LinkedList::add(int data)
{
    Node *p = new Node(data);
    if (head && tail != 0)
    {
        tail->setNext(p);
        tail = p;
        length++;
    }
    else
    {
        head = p;
        tail = p;
        length++;
    }
}

// Display the linked list using loop
void LinkedList::Display()
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->getData() << " ";
        p = p->getNext();
    }
}
// Get the length of the linked list
int LinkedList::getLength()
{
    return length;
}
// Display the linked list using recursion

void LinkedList::DisplayR(Node *p)
{
    if (p != 0)
    {
        cout << p->getData() << " ";
        DisplayR(p->getNext());
    }
}

// Add data before head and make a new head
void LinkedList::Prepend(int data)
{
    Node *newNode = new Node(data);
    if (head != NULL)
    {
        Node *temp = head;
        head = newNode;
        newNode->setNext(temp);
        length++;
    }
    else
    {
        head = newNode;
        tail = newNode;
        length++;
    }
}
// Get the desired index
Node *LinkedList::TraverseToIndex(int index)
{
    Node *temp = head;
    int counter = 0;
    while (counter != index)
    {
        counter++;
        temp = temp->getNext();
    }
    return temp;
}

// Insert data at any point
void LinkedList::Insert(int index, int data)
{
    if (index < 0 || index >= length)
    {
        cout << "Please enter a valid index" << endl;
    }
    else
    {
        Node *newNode = new Node(data);
        Node *prevNode = TraverseToIndex(index - 1);
        Node *nextNode = prevNode->getNext();
        prevNode->setNext(newNode);
        newNode->setNext(nextNode);
    }
}

// Delete the head and make the new head
void LinkedList::RemovePrepend()
{
    Node *prevHead = head;
    Node *newHead = head->getNext();
    head = newHead;
    delete prevHead;
}

// Remove something from the end of the linked list
void LinkedList::pop()
{
    Node *prevTail = tail;
    Node *newTail = TraverseToIndex(length - 2);
    newTail->setNext(NULL);
    tail = newTail;
    delete prevTail;
}

// Delete the data at a given index
void LinkedList::DeleteAtIndex(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Please Enter a valid index" << endl;
    }
    else
    {
        if (index == length - 1)
        {
            pop();
        }
        else
        {
            Node *prevNode = TraverseToIndex(index - 1);
            Node *newNext = prevNode->getNext()->getNext();
            Node *dNode = prevNode->getNext();
            prevNode->setNext(newNext);
            delete dNode;
        }
    }
}

// The List should be sorted in order to remove duplicate
void LinkedList::RemoveDuplicate()
{
    Node *p = head;
    Node *q = p->getNext();
    while (q != NULL)
    {
        if (p->getData() != q->getData())
        {
            p = q;
            q = q->getNext();
        }
        else
        {
            p->setNext(q->getNext());
            delete q;
            q = p->getNext();
        }
    }
}
