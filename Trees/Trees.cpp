#include <iostream>
#include "Trees.h"
#include <queue>

using namespace std;

Node::Node()
{
    LeftChild = NULL;
    data = 0;
    RightChild = NULL;
}

Node::Node(int data)
{
    LeftChild = NULL;
    this->data = data;
    RightChild = NULL;
}

Node::~Node()
{
    delete LeftChild;
    delete RightChild;
}

void Tree::create()
{
    Node *p, *t;
    int x;
    queue<Node *> q;
    cout << "Enter the roor value: ";
    cin >> x;
    root = new Node(x);
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter the left child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node(x);
            p->LeftChild = t;
            q.push(t);
        }
        cout << "Enter the right child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node(x);
            p->RightChild = t;
            q.push(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->LeftChild);
        preorder(p->RightChild);
    }
}

void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->LeftChild);
        cout << p->data << " ";
        Inorder(p->RightChild);
    }
}

void Tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->LeftChild);
        postorder(p->RightChild);
        cout << p->data << " ";
    }
}
