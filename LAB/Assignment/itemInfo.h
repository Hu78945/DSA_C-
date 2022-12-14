#include <iostream>
using namespace std;
class itemInfo
{
private:
    /* data */
    string name;
    int price;
    string rfidTagNumber;
    string OrignalLocation;
    string currentLocation;

public:
    void setRfidNumber(string num);
    void setOrignalLocation(string loc);
    void setCurrentLocation(string loc);
    string getOrignalLocation();
    string getRfidNumber();
    string GetRfidTagNumber();
    string GetCurrentLocation();
    string GetName();
    double GetPrice();
    itemInfo(/* args */);
    itemInfo(string name, int price, string rfidNumber);
    itemInfo(string name, string rfidNumber, int price, string OrignalLocation);
    itemInfo(string name, string rfidNumber, int price, string OrignalLocation, string SCurrentLocation);
    int rifIdToDecimal();
    void printItem();
};
