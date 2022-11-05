#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList MyList = {};
    MyList.add(3);
    MyList.add(5);
    MyList.add(5);
    MyList.add(8);
    MyList.add(8);
    MyList.add(8);
    MyList.Display();
    cout << endl;
    MyList.RemoveDuplicate();
    MyList.Display();
    return 0;
}