#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

Node::Node()
{
    leftChild = NULL;
    data = 0;
    rightChild = NULL;
}

Node::Node(int data)
{
    leftChild = NULL;
    this->data = data;
    rightChild = NULL;
}

// Binary Search tree
BinarySearchTree::BinarySearchTree(/* args */)
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    delete root;
}

// insert function
void BinarySearchTree::insert(int key)
{
    Node *t = root;
    Node *r = NULL, *p;
    if (root == NULL)
    {
        p = new Node(key);
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key == t->data)
            return;
        else if (key < t->data)
            t = t->leftChild;
        else
            t = r->rightChild;
    }

    p = new Node(key);
    if (p->data < r->data)
        r->leftChild = p;
    else
        r->rightChild = p;
}

// insjert function
Node *BinarySearchTree::search(int data)
{
    Node *t = root;
    Node *p;
    while (t != NULL)
    {
        if (t->data = data)
            return t;
        else if (data < t->data)
            t = t->leftChild;
        else
            t = t->rightChild;
    }
    return NULL;
}

void BinarySearchTree::Inorder(Node *n)
{
    if (n)
    {
        Inorder(n->leftChild);
        cout << n->data << " ";
        Inorder(n->rightChild);
    }
}

Node *BinarySearchTree::RInsert(Node *p, int key)
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
        return t;
    }

    if (key < p->data)
    {
        p->leftChild = RInsert(p->leftChild, key);
    }
    else if (key > p->data)
    {
        p->rightChild = RInsert(p->rightChild, key);
    }
    return p;
}

int BinarySearchTree::Height(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->leftChild);
    y = Height(p->rightChild);
    return x > y ? x + 1 : y + 1;
}

Node *BinarySearchTree::Inpre(Node *p)
{
    while (p && p->rightChild != NULL)
    {
        p = p->rightChild;
    }
    return p;
}

Node *BinarySearchTree::InSucc(Node *p)
{
    while (p && p->leftChild != NULL)
    {
        p = p->leftChild;
    }
    return p;
}

Node *BinarySearchTree::Delete(Node *p, int key)
{
    // If the root is NULL
    if (p == NULL)
    {
        return NULL;
    }
    // If the node is leafe node
    if (p->leftChild == NULL && p->rightChild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if (key < p->data)
    {
        p->leftChild = Delete(p->leftChild, key);
    }
    else if (key > p->data)
    {
        p->rightChild = Delete(p->rightChild, key);
    }
    else
    {
        if (Height(p->leftChild) > Height(p->rightChild))
        {
            Node *q = Inpre(p->leftChild);
            p->data = q->data;
            p->leftChild = Delete(p->leftChild, key);
        }
        else
        {
            Node *q = InSucc(p->rightChild);
            p->data = q->data;
            p->rightChild = Delete(p->rightChild, key);
        }
    }
    return p;
}
