#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList MyList = {};
    MyList.add(10);
    MyList.add(20);
    MyList.add(30);
    MyList.add(40);
    MyList.add(50);
    MyList.add(60);
    MyList.Display();
    cout << endl;
    MyList.DeleteAtIndex(2);
    MyList.Display();
    return 0;
}