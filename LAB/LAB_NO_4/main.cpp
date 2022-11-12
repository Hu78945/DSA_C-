#include <iostream>
#include "CarList.h"
using namespace std;

int main()
{
    CarList MyCars = {};
    MyCars.InsertCar("BMW", "XYZ123", "GREEN");
    MyCars.InsertCar("Audi", "yuo456", "GREEN");
    MyCars.InsertCar("OK", "mou789", "GREEN");
    MyCars.InsertCar("NULL", "pop456", "GREEN");
    MyCars.printAll();
    MyCars.insertcarAtPos("Honda", "yts147", "red", 1);
    MyCars.printAll();
    MyCars.removeItemAtEnd();
    MyCars.printAll();
    MyCars.removeCar("pop456");
    MyCars.printAll();
    return 0;
}