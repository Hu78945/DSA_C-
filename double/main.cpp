#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

int main()
{
    DoubleLinkedList MyList = {};
    MyList.append(10);
    MyList.append(20);
    MyList.append(30);
    MyList.append(40);
    MyList.Display();
    MyList.Reverse();
    MyList.Display();
    return 0;
}