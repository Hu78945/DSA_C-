#include <iostream>
using namespace std;

class ItemInfo
{
private:
    /* data */
    string productName;
    double price;
    string rfidTagNumber;
    string orignalLocation;
    string currentLocation;

public:
    ItemInfo();
    ItemInfo(string productName, double price, string rfidTagNumber, string orignalLocation);

    // setter functions
    void setRfidTagNumber(string rfidTag);
    void setOrignalLocation(string orignalLocation);
    void setCurrentLocation(string currentLocation);
    void setPrice(double price);
    // void setProductName(string name);

    // getter functions
    string getRfidTagNumber();
    string getOrignalLocation();
    string getCurrentLocation();

    // Display Function
    void Display();
};

class ItemInfoNode
{
private:
    ItemInfoNode *prev;
    ItemInfoNode *next;
    ItemInfo data;

public:
    ItemInfoNode();
    ItemInfoNode(string productName, double price, string rfidTagNumber, string orignalLocation);

    // setter functions
    void setPrev(ItemInfoNode *prev);
    void setNext(ItemInfoNode *next);

    // getter function
    ItemInfoNode *getNext();
    ItemInfoNode *getPrev();
    friend class ItemList;
};

class ItemList
{
private:
    ItemInfoNode *head;
    ItemInfoNode *tail;

public:
    ItemList();
    void insertInfo(string name, string rfidTag, double price, string initPostion);
    void Display();
    void moveItem(string rfidTag, string source, string dest);
    void cleanStore();
    void checkOut(string cartNumber);
    void RemoveAllPurchased();
    void printByLocation(string location);
    void PrintByRfidNumber(string rfi);
};

class DepartmentStore
{
public:
    void Menue();
};