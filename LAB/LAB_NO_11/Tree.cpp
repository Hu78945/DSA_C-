#include <iostream>
#include "Tree.h"
#include <queue>
#include <stack>

using namespace std;

Node::Node()
{
    LeftChild = NULL;
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
    char x;
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
        if (!(x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z'))
        {
            t = new Node(x);
            length++;
            p->LeftChild = t;
            q.push(t);
        }
        cout << "Enter the right child of " << p->data << " : ";
        cin >> x;
        if (!(x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z'))
        {
            t = new Node(x);
            length++;
            p->RightChild = t;
            q.push(t);
        }
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
