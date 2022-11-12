#include <iostream>
using namespace std;

class CarInfo
{
private:
    string Name;
    char PlatNumberAlphabat[3];
    int PlateNumber[3] = {0};
    string Color;
    CarInfo *next;

public:
    CarInfo();
    CarInfo(string Name, string PlatNumber1, string Color1);
    // getter functions
    string getName();
    string getPlateNumber();
    string getColor();
    CarInfo *getNext();
    // setter functions
    void setName(string name);
    void setPlateNumber(string PlateNumber);
    void setColor(string color);
    void setNext(CarInfo *next);
    // Display function
    void Display();
};

class CarList
{
private:
    CarInfo *head;
    int length;

public:
    CarList();
    void InsertCar(string name, string PlateNumber, string Color);
    void insertcarAtPos(string name, string PlateNumber, string Color, int position);
    void removeCar(string PlateNumber);
    void removeItemAtEnd();
    void printAll();
};