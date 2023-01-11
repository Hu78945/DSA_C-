#include <iostream>
using namespace std;

class Node
{
private:
public:
    Node *LeftChild;
    char data;
    Node *RightChild;

    Node();
    Node(int data);
    ~Node();
};

class Tree
{
public:
    Node *root = NULL;
    int length = 1;
    void create();
    // using recursion
    void Inorder(Node *p);
};
