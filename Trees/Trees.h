#include <iostream>
using namespace std;

class Node
{
private:
public:
    Node *LeftChild;
    int data;
    Node *RightChild;

    Node();
    Node(int data);
    ~Node();
};

class Tree
{
public:
    Node *root = NULL;
    void create();
    // using recursion
    void preorder(Node *p);
    void Inorder(Node *p);
    void postorder(Node *p);
    // using traversal
    void Tpreorder(Node *t);
    void Tinorder(Node *t);
};
