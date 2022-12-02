#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node();
    Node(int data);
    friend class Queue;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue();
    void enqueu(int data);
    void dequeu();
    bool isEmpty();
    bool isFull();
    void Display();
};
