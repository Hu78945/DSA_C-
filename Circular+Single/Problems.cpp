#include <iostream>
#include <cmath>
#include "Problems.h"
using namespace std;

bool checkLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (slow && fast)
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
        if (fast == slow)
        {
            return true;
        }
    }
    cout << "Does not exist" << endl;
    return false;
}

Node *findMiddleElement(Node *list)
{
    // get the length of the linked list
    Node *p = list;
    int length = 0;
    int len;
    while (p != NULL)
    {
        length++;
        p = p->getNext();
    }
    length--;
    // get the middle element
    int middle = (length / 2);
    Node *middlePoint = list;
    // traverse the linked list for middle point
    for (int i = 0; i < middle; i++)
    {
        middlePoint = middlePoint->getNext();
    }
    return middlePoint;
}

Node *Intersection(Node *first, Node *second)
{
    Node *p = first;
    Node *q = second;
    while (p)
    {
        p = p->getNext();
    }
    while (q)
    {
        q = q->getNext();
    }
}
