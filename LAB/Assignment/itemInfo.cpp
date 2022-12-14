#include <iostream>
#include <string.h>
#include <math.h>
#include "itemInfo.h"
using namespace std;

// helper functions

// set the rfid Number
void itemInfo::setRfidNumber(string rfidNumber)
{
    int counter = 0;
    for (int i = 0; rfidNumber[i] != '\0'; i++)
    {

        if (rfidNumber[i] >= 'A' && rfidNumber[i] <= 'F')
        {
            this->rfidTagNumber += rfidNumber[i];
            counter++;
        }
        else if (rfidNumber[i] >= 'a' && rfidNumber[i] <= 'f')
        {
            this->rfidTagNumber += rfidNumber[i];
            counter++;
        }
        else if (rfidNumber[i] == '0' || rfidNumber[i] == '1' || rfidNumber[i] == '2' || rfidNumber[i] == '3' || rfidNumber[i] == '4' || rfidNumber[i] == '5' || rfidNumber[i] == '6' || rfidNumber[i] == '7' || rfidNumber[i] == '8' || rfidNumber[i] == '9')
        {
            this->rfidTagNumber += rfidNumber[i];
            counter++;
        }

        else
        {
            cout << "Please enter a valid hexadecimal code" << endl;
            break;
        }
    }
    rfidTagNumber[counter] = '\0';
}

// set the orignal location of the item
void itemInfo::setOrignalLocation(string loc)
{
    if (loc.length() > 6)
    {
        cout << "Please enter a valid location" << endl;
    }
    else
    {

        OrignalLocation = loc;
        setCurrentLocation("");
    }
}

// set the current location of the item
void itemInfo::setCurrentLocation(string loc)
{
    if (loc == "")
    {
        if (OrignalLocation != "")
        {
            currentLocation = OrignalLocation;
        }
    }
    else
    {
        currentLocation = loc;
    }
}

// Constructores
itemInfo::itemInfo()
{
    price = 0;
}

itemInfo::itemInfo(string name, int price, string rfidNumber)
{
    this->name = name;
    this->price = price;
    setRfidNumber(rfidNumber);
    setOrignalLocation("s00001");
}

itemInfo::itemInfo(string name, string rfidNumber, int price, string OrignalLocation)
{
    this->name = name;
    this->price = price;
    setRfidNumber(rfidNumber);
    setOrignalLocation(OrignalLocation);
}

string itemInfo::getRfidNumber()
{
    for (int i = 0; rfidTagNumber[i] != '\0'; i++)
    {
        cout << rfidTagNumber[i];
    }
}

string itemInfo::GetRfidTagNumber()
{
    return rfidTagNumber;
}

// Display Function
void itemInfo::printItem()
{
    cout << "Name:  " << name << endl;
    cout << "Price:  " << price << endl;
    cout << "RFID_Number:   ";
    getRfidNumber();
    cout << endl;
    cout << "Orignal_Location:  " << OrignalLocation << endl;
    cout << "Current_Location:  " << currentLocation << endl;
}

// Decimal Form of RfidNumber

int itemInfo::rifIdToDecimal()
{
    int num = 0;
    int pow = 0;
    for (int i = 0; i < rfidTagNumber.length(); i++)
    {
        switch (rfidTagNumber[i])
        {
        case 'A':
        {
            int power = 16 * pow;
            num += 10 * power;
            pow++;
        }
        case 'B':
        {
            int power = 16 * pow;
            num += 11 * power;
            pow++;
        }
        case 'C':
        {
            int power = 16 * pow;
            num += 12 * power;
            pow++;
        }
        case 'D':
        {
            int power = 16 * pow;
            num += 13 * power;
            pow++;
        }
        case 'E':
        {
            int power = 16 * pow;
            num += 14 * power;
            pow++;
        }
        case 'F':
        {
            int power = 16 * pow;
            num += 15 * power;
            pow++;
        }
        case 0:
        {
            int power = 16 * pow;
            num += 0 * power;
            pow++;
        }
        case 1:
        {
            int power = 16 * pow;
            num += 1 * power;
            pow++;
        }
        case 2:
        {
            int power = 16 * pow;
            num += 2 * power;
            pow++;
        }
        case 3:
        {
            int power = 16 * pow;
            num += 3 * power;
            pow++;
        }
        case 4:
        {
            int power = 16 * pow;
            num += 4 * power;
            pow++;
        }
        case 5:
        {
            int power = 16 * pow;
            num += 5 * power;
            pow++;
        }
        case 6:
        {
            int power = 16 * pow;
            num += 6 * power;
            pow++;
        }
        case 7:
        {
            int power = 16 * pow;
            num += 7 * power;
            pow++;
        }
        case 8:
        {
            int power = 16 * pow;
            num += 8 * power;
            pow++;
        }
        case 9:
        {
            int power = 16 * pow;
            num += 9 * power;
            pow++;
        }

        default:
            break;
        }
    }
    return num;
}

// get the orignal location
string itemInfo::getOrignalLocation()
{
    return OrignalLocation;
}

// get the current location
string itemInfo::GetCurrentLocation()
{
    return currentLocation;
}

// get the name
string itemInfo::GetName()
{
    return name;
}

// get the price
double itemInfo::GetPrice()
{
    return price;
}

itemInfo::itemInfo(string name, string rfidNumber, int price, string OrignalLocation, string CurrentLocation)
{
    this->name = name;
    this->rfidTagNumber = rfidNumber;
    this->price = price;
    this->OrignalLocation = OrignalLocation;
    this->currentLocation = CurrentLocation;
}
