#include <iostream>
#include "Staff.h"

class Node
{
private:
    Staff data;
    Node *next;

public:
    Node();
    Node(Staff data);
    Node(Staff data, Node *next);
    Node *getNext();
    void setNext(Node *next);
    Staff getData();
    void setData(Staff data);
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length = 0;

public:
    // Constructor
    LinkedList();
    LinkedList(Node *item);
    // Destructor
    ~LinkedList();
    // Display Function
    void Display();
    void DisplayR(Node *p);
    // Generic Functions
    Node *GetHead();
    int getLength();
    // Insertion Functions
    void add(Staff data);
    void Prepend(Staff data);
    void Insert(int index, Staff data);
    // Helper Function
    Node *TraverseToIndex(int index);
    // DeletionFunction
    void RemovePrepend();
    void pop();
    void DeleteAtIndex(int index);
    // Remove Duplicate
    void RemoveDuplicate();
    // Reverse the linked list by reversing the elements
    void ReverseMeyhode1();
    // Reverse the linked list by reversing the links
    // Note: it will break the tail
    void ReverseMethoed2();

    // Reverse a linked list recursively
    void ReverseR(Node *q, Node *p);

    // Concat a linked list
    void Concat(LinkedList l1);

    // Merge two linked list
    static void Merge(LinkedList first, LinkedList second);
};
