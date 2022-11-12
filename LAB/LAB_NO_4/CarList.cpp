#include <iostream>
#include <string>
#include "CarList.h"
using namespace std;

CarInfo::CarInfo()
{
    next = NULL;
}

CarInfo::CarInfo(string Name, string PlatNumber1, string Color1)
{
    this->Name = Name;
    this->Color = Color1;
    next = NULL;
    setPlateNumber(PlatNumber1);
}

// getter functions
string CarInfo::getName()
{
    return Name;
}

string CarInfo::getPlateNumber()
{
    string num;
    for (int i = 0; i < 3; i++)
    {
        num += PlatNumberAlphabat[i];
    }

    num += to_string(PlateNumber[0]);

    return num;
}

string CarInfo::getColor()
{
    return Color;
}

CarInfo *CarInfo::getNext()
{
    return next;
}

// setter functions
void CarInfo::setName(string name)
{
    Name = name;
}

void CarInfo::setPlateNumber(string PlateNumber)
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        if (PlateNumber[i] >= 'A' && PlateNumber[i] <= 'Z' || PlateNumber[i] >= 'a' && PlateNumber[i] <= 'z')
        {
            this->PlatNumberAlphabat[i] = PlateNumber[i];
            counter++;
        }
    }

    if (counter == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            string str = PlateNumber.substr(3, 4);
            int num = stoi(str);
            this->PlateNumber[i] = num;
            counter++;
        }
    }
    else
    {
        cout << "First three places must be alphbat and next three places must be number" << endl;
        cout << "Now the Plate number will be set to null" << endl;
        cout << counter;
        return;
    }
    if (counter != 6)
    {
        PlateNumber = '\0';
    }
}

void CarInfo::setColor(string color)
{
    Color = color;
}

void CarInfo::setNext(CarInfo *next)
{
    this->next = next;
}

void CarInfo::Display()
{
    cout << "Car Name: " << Name << endl;
    cout << "Car Plate Number: " << getPlateNumber() << endl;
    cout << "Car Color: " << Color << endl;
    cout << "------------------------------------------------------" << endl;
}

CarList::CarList()
{
    head = NULL;
    length = 0;
}

void CarList::InsertCar(string name, string PlateNumber, string Color)
{
    CarInfo *car = new CarInfo(name, PlateNumber, Color);
    if (head == NULL)
    {
        head = car;
        length = 1;
    }
    else
    {
        CarInfo *tempHead = head;
        head = car;
        car->setNext(tempHead);
        length++;
    }
}

void CarList::printAll()
{
    CarInfo *temp = head;
    for (int i = 0; i < length; i++)
    {
        temp->Display();
        temp = temp->getNext();
    }
}

void CarList::insertcarAtPos(string name, string PlateNumber, string Color, int position)
{
    CarInfo *newNode = new CarInfo(name, PlateNumber, Color);

    if (position == 0)
    {
        CarInfo *temp = head;
        head = newNode;
        newNode->setNext(temp);
        length++;
        return;
    }
    int counter = 0;
    CarInfo *prevNode = head;
    while (counter != position - 1)
    {
        prevNode = prevNode->getNext();
        counter++;
    }
    CarInfo *tempNext = prevNode->getNext();
    prevNode->setNext(newNode);
    newNode->setNext(tempNext);
    length++;
}

void CarList::removeCar(string PlateNumber)
{
    int num = 0;
    CarInfo *node = head;
    while (node != NULL)
    {
        if (node->getPlateNumber() == PlateNumber)
        {
            break;
        }

        num++;
        node = node->getNext();
    }
    if (num == 0)
    {
        head = head->getNext();
        length--;
    }
    else
    {
        int counter = 0;
        CarInfo *prevNode = head;
        while (counter != num - 2)
        {
            prevNode = prevNode->getNext();
            counter++;
        }
        CarInfo *dNode = prevNode->getNext();
        prevNode->setNext(prevNode->getNext()->getNext());
        delete dNode;
        length--;
    }
}

void CarList::removeItemAtEnd()
{
    int counter = 0;
    CarInfo *node = head;
    while (counter != length - 2)
    {
        node = node->getNext();
        counter++;
    }
    CarInfo *dNode = node->getNext();
    node->setNext(node->getNext()->getNext());
    length--;
}
