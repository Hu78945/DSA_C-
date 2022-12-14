#include "ItemInfoNode.h"
using namespace std;

// ItemInfo Node Class

ItemInfoNode::ItemInfoNode()
{
    next = NULL;
    prev = NULL;
    data = {};
}

ItemInfoNode::ItemInfoNode(string name, string rfidNumber, int price, string OrignalLocation)
{
    data = {name, rfidNumber, price, OrignalLocation};
    next = NULL;
    prev = NULL;
}

ItemInfoNode::ItemInfoNode(string name, string rfidNumber, int price, string OrignalLocation, string currentLocation)
{
    data = {name, rfidNumber, price, OrignalLocation, currentLocation};
    next = NULL;
    prev = NULL;
}
