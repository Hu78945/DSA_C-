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
};
