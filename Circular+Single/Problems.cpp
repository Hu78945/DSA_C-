#include <iostream>
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