#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList MyList = {};
    MyList.add(1);
    MyList.add(2);
    MyList.add(3);
    MyList.add(4);
    MyList.add(5);
    MyList.add(6);
    MyList.Display();
    cout << endl;
    MyList.ReverseR(NULL, MyList.GetHead());
    MyList.Display();
    cout << endl;

    return 0;
}