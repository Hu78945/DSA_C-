#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    int height;
    Node *rchild;

    Node();
    Node(int data);
};

class AVL
{
public:
    Node *root;
    AVL();
    Node *RInsert(Node *p, int key);
    int NodeHeight(Node *p);
    int BlanceFactor(Node *p);
    // rotations
    Node *LLrotation(Node *p);
    Node *LRrotation(Node *p);
    Node *RRrotation(Node *p);
    Node *RLrotation(Node *p);
};