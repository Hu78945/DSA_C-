#include <iostream>
#include "ItemInfoNode.h"
using namespace std;

class ItemList
{
private:
    ItemInfoNode *Head;
    ItemInfoNode *Tail;
    int length;

public:
    ItemList();
    ~ItemList();
    void insertInfo(string name, string rfidTag, double price, string initPosition);
    void insertInfo2(string name, string rfidTag, double price, string initPosition, string currentLocation);
    void insertNode(ItemInfoNode *node);
    void Display();
    bool moveItem(string rfidTag, string source, string dest);
    void checkOut(string cartNumber);
    int getTotal();
    void printByLocation(string loc);
    void cleanStore();
    void removeAllPurchasedItem();
    void PrintByRfidNumber(string rfidNumber);
};
