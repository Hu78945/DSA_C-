#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    Staff CEO = {"ME", 1, "CEO", 2000000};
    Staff Manger = {"You", 2, "Assitant-Manger", 25000};
    LinkedList MyList = {};
    MyList.add(CEO);
    MyList.add(Manger);
    MyList.Display();
}