#include <iostream>
using namespace std;

class Node
{
public:
    Node *leftChild;
    int data;
    Node *rightChild;

    Node();
    Node(int data);
};

class BinarySearchTree
{

public:
    Node *root;
    BinarySearchTree(/* args */);
    void insert(int key);
    Node *search(int data);
    void Inorder(Node *n);
    Node *RInsert(Node *p, int key);
    Node *Delete(Node *p, int key);
    int Height(Node *p);
    Node *Inpre(Node *p);
    Node *InSucc(Node *p);
    ~BinarySearchTree();
};
