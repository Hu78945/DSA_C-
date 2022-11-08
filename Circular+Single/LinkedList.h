#include <iostream>

class Node
{
private:
    int data;
    Node *next;

public:
    Node();
    Node(int data);
    Node(int data, Node *next);
    Node *getNext();
    void setNext(Node *next);
    int getData();
    void setData(int data);
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
    void add(int data);
    void Prepend(int data);
    void Insert(int index, int data);
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

class CircularLinkedList
{
public:
    Node *Head;
    int length;
    CircularLinkedList();
    CircularLinkedList(Node *item);
    void Display();
    void insert(int index, int item);
    void add(int item);
    void DeleteHead();
    void DeleteAtIndex(int index);
};
