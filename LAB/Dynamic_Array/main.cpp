#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    Array myArray = {};
    myArray.push(20);
    myArray.PrintArray();

    myArray.push(30);
    myArray.PrintArray();

    myArray.push(40);
    myArray.PrintArray();

    myArray.push(50);
    myArray.PrintArray();

    myArray.push(60);
    myArray.PrintArray();

    myArray.push(70);
    myArray.PrintArray();
    return 0;
}