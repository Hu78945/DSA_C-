#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node();
    Node(int data);
};

class Tree
{
public:
    Node *root = NULL;
    void create();
    void levelOrder(Node *r);
};