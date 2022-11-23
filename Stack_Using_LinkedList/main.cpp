#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack list = {};
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    list.Display();
    return 0;
}