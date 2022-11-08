#include <iostream>
#include "Problems.h"
using namespace std;

int main()
{
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    n1->setNext(n2);
    n2->setNext(n3);
    n3->setNext(n4);
    // n4->setNext(NULL);
    // setting a loop here
    n4->setNext(n1);

    // bool res = checkLoop(n1);

    CircularLinkedList MyList = {n1};
    MyList.Display();
    MyList.DeleteAtIndex(-1);
    MyList.Display();
    return 0;
}