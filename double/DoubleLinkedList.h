#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node();
    Node(int data);
};

class DoubleLinkedList
{
public:
    Node *head;
    Node *tail;
    int length;
    DoubleLinkedList();
    DoubleLinkedList(int data);
    void append(int data);
    void Display();
    void Insert(int index, int data);
    Node *TraverseToIndex(int index);
    void Delete();
    void DeleteAtIndex(int index);
    void Reverse();
    ~DoubleLinkedList();
};
