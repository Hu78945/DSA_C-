#include <iostream>
#include "AVL.h"
using namespace std;

Node::Node()
{
    lchild = NULL;
    data = 0;
    height = 0;
    rchild = NULL;
}
Node::Node(int data)
{
    lchild = NULL;
    this->data = data;
    height = 0;
    rchild = NULL;
}

AVL::AVL()
{
    root = NULL;
}

int AVL::NodeHeight(Node *p)
{
    int heightOfLeftSubTree, heightOfRightSubTree;
    heightOfLeftSubTree = p && p->lchild ? p->lchild->height : 0;
    heightOfRightSubTree = p && p->rchild ? p->rchild->height : 0;

    return heightOfLeftSubTree > heightOfRightSubTree ? heightOfLeftSubTree + 1 : heightOfRightSubTree + 1;
}

int AVL::BlanceFactor(Node *p)
{
    int heightOfLeftSubTree, heightOfRightSubTree;
    heightOfLeftSubTree = p && p->lchild ? p->lchild->height : 0;
    heightOfRightSubTree = p && p->rchild ? p->rchild->height : 0;

    return heightOfLeftSubTree - heightOfRightSubTree;
}

Node *AVL::LLrotation(Node *p)
{
    Node *PLchild = p->lchild;
    Node *PLchild_RightChild = PLchild->rchild;

    PLchild->rchild = p;
    p->lchild = PLchild_RightChild;
    p->height = NodeHeight(p);
    PLchild->height = NodeHeight(PLchild);

    if (root == p)
        root = PLchild;
    return PLchild;
}

Node *AVL::LRrotation(Node *p)
{
    return NULL;
}
Node *AVL::RRrotation(Node *p)
{
    Node *PRchild = p->rchild;
    Node *PRchild_LeftChild = PRchild->lchild;

    PRchild->lchild = p;
    p->rchild = PRchild_LeftChild;
    p->height = NodeHeight(p);
    PRchild->height = NodeHeight(PRchild);

    if (root == p)
        root = PRchild;
    return PRchild;
}
Node *AVL::RLrotation(Node *p)
{
    return NULL;
}

Node *AVL::RInsert(Node *p, int key)
{
    Node *t;
    if (root == NULL)
    {
        t = new Node(key);
        root = t;
        return root;
    }
    if (p == NULL)
    {
        t = new Node(key);
        t->height = 1;
        return t;
    }

    if (key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RInsert(p->rchild, key);
    }
    p->height = NodeHeight(p);

    if (BlanceFactor(p) == 2 && BlanceFactor(p->lchild) == 1)
    {
        return LLrotation(p);
    }
    else if (BlanceFactor(p) == 2 && BlanceFactor(p->lchild) == -1)
    {
        return LRrotation(p);
    }
    else if (BlanceFactor(p) == -2 && BlanceFactor(p->lchild) == -1)
    {
        return RRrotation(p);
    }
    else if (BlanceFactor(p) == -2 && BlanceFactor(p->lchild) == 1)
    {
        return RLrotation(p);
    }
    return p;
}