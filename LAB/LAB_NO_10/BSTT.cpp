#include <iostream>
#include "BSTT.h"
using namespace std;

BSTTNode::BSTTNode()
{
    leftChild = NULL;
    data = 0;
    rightChild = NULL;
}

BSTTNode::BSTTNode(int data)
{
    leftChild = NULL;
    this->data = data;
    rightChild = NULL;
}

BSTTNode *BSTTNode::getLeftChild()
{
    return leftChild;
}

int BSTTNode::getData()
{
    return data;
}

BSTTNode *BSTTNode::getRightChild()
{
    return rightChild;
}

void BSTTNode::setRightChild(BSTTNode *data)
{
    this->rightChild = data;
}

void BSTTNode::setLeftChild(BSTTNode *data)
{
    this->leftChild = data;
}

void BSTTNode::setData(int data)
{
    this->data = data;
}

BinarySearchTree::BinarySearchTree(/* args */)
{
    root = NULL;
}

void BinarySearchTree::Inorder(BSTTNode *n)
{
    if (n)
    {
        Inorder(n->getLeftChild());
        cout << n->getData() << " ";
        Inorder(n->getRightChild());
    }
}

BSTTNode *BinarySearchTree::RInsert(BSTTNode *p, int key)
{
    BSTTNode *t;
    if (root == NULL)
    {
        t = new BSTTNode(key);
        root = t;
        return root;
    }
    if (p == NULL)
    {
        t = new BSTTNode(key);
        return t;
    }

    if (key < p->getData())
    {
        p->setLeftChild(RInsert(p->getLeftChild(), key));
    }
    else if (key > p->getData())
    {
        p->setRightChild(RInsert(p->getRightChild(), key));
    }
    return p;
}

int BinarySearchTree::Height(BSTTNode *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->getLeftChild());
    y = Height(p->getRightChild());
    return x > y ? x + 1 : y + 1;
}

BSTTNode *BinarySearchTree::Inpre(BSTTNode *p)
{
    while (p && p->getRightChild() != NULL)
    {
        p = p->getRightChild();
    }
    return p;
}

BSTTNode *BinarySearchTree::InSucc(BSTTNode *p)
{
    while (p && p->getLeftChild() != NULL)
    {
        p = p->getLeftChild();
    }
    return p;
}

BSTTNode *BinarySearchTree::Delete(BSTTNode *p, int key)
{
    // If the root is NULL
    if (p == NULL)
    {
        return NULL;
    }
    // If the node is leafe node
    if (p->getLeftChild() == NULL && p->getRightChild() == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if (key < p->getData())
    {
        p->setLeftChild(Delete(p->getLeftChild(), key));
    }
    else if (key > p->getData())
    {
        p->setRightChild(Delete(p->getRightChild(), key));
    }
    else
    {
        if (Height(p->getLeftChild()) > Height(p->getRightChild()))
        {
            BSTTNode *q = Inpre(p->getLeftChild());
            p->setData(q->getData());
            p->setLeftChild(Delete(p->getLeftChild(), key));
        }
        else
        {
            BSTTNode *q = InSucc(p->getRightChild());
            p->setData(q->getData());
            p->setRightChild(Delete(p->getRightChild(), key));
        }
    }
    return p;
}
