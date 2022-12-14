#include <iostream>
#include "itemInfo.h"
using namespace std;
class ItemInfoNode
{
private:
public:
    ItemInfoNode *next;
    ItemInfoNode *prev;
    itemInfo data;

    ItemInfoNode();
    ItemInfoNode(string name, string rfidNumber, int price, string OrignalLocation);
    ItemInfoNode(string name, string rfidNumber, int price, string OrignalLocation, string currentLocation);
};
