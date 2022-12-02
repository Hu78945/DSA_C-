#include <iostream>
#include "Queues.h"
using namespace std;

int main()
{
    Queue list = {};
    list.enqueue(10);
    list.enqueue(20);
    list.enqueue(30);
    list.enqueue(40);
    list.Display();
    list.dequeue();
    list.Display();

    return 0;
}