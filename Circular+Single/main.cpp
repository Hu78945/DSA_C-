#include <iostream>
#include "Problems.h"
using namespace std;

int main()
{
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    // Node *n5 = new Node(50);
    // Node *n6 = new Node(60);
    // Node *n7 = new Node(70);
    n1->setNext(n2);
    n2->setNext(n3);
    n3->setNext(n4);
    // n4->setNext(n5);
    // n5->setNext(n6);
    // n6->setNext(n7);
    // setting a loop here
    // n4->setNext(n1);

    // bool res = checkLoop(n1);

    // CircularLinkedList MyList = {n1};
    // MyList.Display();
    // MyList.DeleteAtIndex(-1);
    // MyList.Display();

    Node *res = findMiddleElement(n1);
    cout << res->getData() << endl;
    return 0;
}