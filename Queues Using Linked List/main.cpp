#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue list = {};
    list.enqueu(10);
    list.enqueu(20);
    list.enqueu(30);
    list.enqueu(40);
    list.enqueu(50);
    list.Display();
    list.dequeu();
    list.dequeu();
    list.dequeu();
    list.Display();
    return 0;
}