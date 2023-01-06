#include <iostream>
#include <queue>
#include "Tree.h"
using namespace std;

Node::Node()
{
    lchild = NULL;
    data = 0;
    rchild = NULL;
}
Node::Node(int data)
{
    lchild = NULL;
    this->data = data;
    rchild = NULL;
}

void Tree::create()
{

    Node *p, *t;
    int x;
    queue<Node *> q;
    cout << "Enter the root value: ";
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
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter the right child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node(x);
            p->rchild = t;
            q.push(t);
        }
    }
}

void Tree::levelOrder(Node *r)
{
    if (root == NULL)
    {
        cout << "Tree does not exist" << endl;
    }
    else
    {

        queue<Node *> q;
        cout << r->data << " ";
        q.push(r);
        while (!q.empty())
        {
            r = q.front();
            q.pop();
            if (r->lchild)
            {
                cout << r->lchild->data << " ";
                q.push(r->lchild);
            }
            if (r->rchild)
            {
                cout << r->rchild->data << " ";
                q.push(r->rchild);
            }
        }
    }
}
