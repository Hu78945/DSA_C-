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

void Node::setData(int data)
{
    this->data = data;
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

void LinkedList::ReverseMeyhode1()
{
    int Arr[length];
    Node *p = head;
    int i = 0;
    while (p != NULL)
    {
        Arr[i] = p->getData();
        i++;
        p = p->getNext();
    }
    p = head;
    i--;
    while (p != NULL)
    {
        p->setData(Arr[i]);
        i--;
        p = p->getNext();
    }
}

void LinkedList::ReverseMethoed2()
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->getNext();
        q->setNext(r);
    }
    tail = head;
    head = q;
}

void LinkedList::ReverseR(Node *q, Node *p)
{
    if (p != NULL)
    {
        ReverseR(p, p->getNext());
        p->setNext(q);
    }
    else
    {
        head = q;
    }
}

void LinkedList::Concat(LinkedList l1)
{
    tail->setNext(l1.head);
    l1.head = NULL;
    tail = l1.tail;
    l1.tail = NULL;
}

void LinkedList::Merge(LinkedList first, LinkedList second)
{
    Node *first1 = first.head;
    Node *second1 = second.head;
    Node *last = NULL;
    Node *third = NULL;
    if (first1->getData() < second1->getData())
    {
        third = last = first1;
        first1->setNext(first1->getNext());
        third->setNext(NULL);
    }
    else
    {
        third = last = second1;
        second1->setNext(second1->getNext());
        third->setNext(NULL);
    }
    while (first1 != NULL && second1 != NULL)
    {
        if (first1->getData() < second1->getData())
        {
            last->setNext(first1);
            last = first1;
            first1->setNext(first1->getNext());
            last->setNext(NULL);
        }
        else
        {
            last->setNext(second1);
            last = second1;
            second1->setNext(second1->getNext());
            last->setNext(NULL);
        }
    }
    if (first1 != NULL)
    {
        last->setNext(first1);
    }
    else
    {
        last->setNext(second1);
    }

    Node *p = third;
    while (p != NULL)
    {
        cout << p->getData() << " ";
    }
}

CircularLinkedList::CircularLinkedList()
{
    Head = NULL;
}

CircularLinkedList::CircularLinkedList(Node *item)
{
    Head = item;
    length = 1;
}
void CircularLinkedList::Display()
{
    Node *p = Head;
    do
    {
        cout << p->getData() << " ";
        p = p->getNext();
    } while (p != Head);
    cout << endl;
}

void CircularLinkedList::insert(int index, int item)
{
    if (index > 0)
    {
        Node *newNode = new Node(item);

        Node *p = Head;
        int counter = 0;
        while (counter != index - 1)
        {
            counter++;
            p = p->getNext();
        }
        Node *tempNext = p->getNext();
        newNode->setNext(tempNext);
        p->setNext(newNode);
    }
}

void CircularLinkedList::add(int item)
{
    Node *p = Head;
    Node *t = new Node(item);
    t->setNext(Head);
    if (Head == NULL)
    {
        Head = t;
        Head->setNext(t);
    }
    else
    {

        while (p->getNext() != Head)
        {
            p = p->getNext();
        }
        p->setNext(t);
        Head = t;
    }
}

void CircularLinkedList::DeleteHead()
{
    Node *temp = Head->getNext();
    Node *head = Head;
    Node *p = Head;
    while (p->getNext() != Head)
    {
        p = p->getNext();
    }
    p->setNext(temp);
    Head = temp;
    delete head;
}

void CircularLinkedList::DeleteAtIndex(int index)
{
    if (index > 0)
    {
        Node *p = Head;
        int counter = 0;
        while (counter != index - 1)
        {
            counter++;
            p = p->getNext();
        }
        Node *temp = p->getNext()->getNext();
        Node *dNode = p->getNext();
        p->setNext(temp);
        delete dNode;
    }
    else if (index == 0)
    {
        DeleteHead();
    }
    else
    {
        cout << "Please enter a valid index" << endl;
    }
}
