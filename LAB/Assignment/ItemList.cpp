#include <iostream>
#include "ItemList.h"
using namespace std;

ItemList::ItemList()
{
    Head = NULL;
    Tail = NULL;
    length = 0;
}

ItemList::~ItemList()
{
    delete Head;
    delete Tail;
}

void ItemList::insertInfo(string name, string rfidTag, double price, string initPosition)
{
    ItemInfoNode *newNode = new ItemInfoNode(name, rfidTag, price, initPosition);
    if (Head && Tail)
    {
        int dec = newNode->data.rifIdToDecimal();
        ItemInfoNode *temp = Head;
        bool con = true;
        while (temp)
        {
            int dec2 = temp->data.rifIdToDecimal();
            if (dec < dec2)
            {
                ItemInfoNode *previousNode = temp->prev;
                ItemInfoNode *next = previousNode->next;
                previousNode->next = newNode;
                newNode->next = next;
                newNode->prev = previousNode;
                length++;
                con = false;
                cout << "Product have been added successfully" << endl;
            }
            temp = temp->next;
        }
        if (con)
        {
            newNode->prev = Tail;
            Tail->next = newNode;
            Tail = newNode;
            length++;
            cout << "Product have been added successfully" << endl;
        }
    }
    else
    {
        Head = newNode;
        Tail = newNode;
        length++;
        cout << "Product have been added successfully" << endl;
    }
}

void ItemList::Display()
{

    ItemInfoNode *temp = Head;
    if (temp == NULL)
        cout << "There are no item in the List" << endl;
    while (temp)
    {
        temp->data.printItem();
        cout << "---------------------------------------------------" << endl;
        temp = temp->next;
    }
}

bool ItemList::moveItem(string rfidTag, string source, string dest)
{
    ItemInfoNode *temp = Head;
    bool con = false;
    while (temp)
    {
        if (temp->data.GetRfidTagNumber() == rfidTag)
        {
            if (temp->data.getOrignalLocation() == source)
            {
                temp->data.setCurrentLocation(dest);
                con = true;
            }
        }
        temp = temp->next;
    }

    return con;
}

void ItemList::insertNode(ItemInfoNode *node)
{
    node->next = NULL;
    node->prev = NULL;
    if (Head && Tail)
    {
        int dec = node->data.rifIdToDecimal();
        ItemInfoNode *temp = Head;
        bool con = true;
        while (temp)
        {
            int dec2 = temp->data.rifIdToDecimal();
            if (dec < dec2)
            {
                ItemInfoNode *previousNode = temp->prev;
                ItemInfoNode *next = previousNode->next;
                previousNode->next = node;
                node->next = next;
                node->prev = previousNode;
                length++;
                con = false;
            }
            temp = temp->next;
        }
        if (con)
        {
            node->prev = Tail;
            Tail->next = node;
            Tail = node;
            length++;
            cout << "Product have been added successfully" << endl;
        }
    }
    else
    {
        Head = node;
        Tail = node;
        length++;
        cout << "Product have been added successfully" << endl;
    }
}

int ItemList::getTotal()
{
    int total = 0;
    ItemInfoNode *temp = Head;
    while (temp)
    {
        total += temp->data.GetPrice();
        temp = temp->next;
    }
    return total;
}

void ItemList::insertInfo2(string name, string rfidTag, double price, string initPosition, string currentLocation)
{
    ItemInfoNode *newNode = new ItemInfoNode(name, rfidTag, price, initPosition, currentLocation);
    if (Head && Tail)
    {
        int dec = newNode->data.rifIdToDecimal();
        ItemInfoNode *temp = Head;
        bool con = true;
        while (temp)
        {
            int dec2 = temp->data.rifIdToDecimal();
            if (dec < dec2)
            {
                ItemInfoNode *previousNode = temp->prev;
                ItemInfoNode *next = previousNode->next;
                previousNode->next = newNode;
                newNode->next = next;
                newNode->prev = previousNode;
                length++;
                con = false;
            }
            temp = temp->next;
        }
        if (con)
        {
            newNode->prev = Tail;
            Tail->next = newNode;
            Tail = newNode;
            length++;
        }
    }
    else
    {
        Head = newNode;
        Tail = newNode;
        length++;
    }
}

void ItemList::checkOut(string cartNumber)
{
    ItemInfoNode *temp = Head;
    ItemList list1 = {};
    while (temp != NULL)
    {
        if (temp->data.GetCurrentLocation() == cartNumber)
        {
            temp->data.setCurrentLocation("out");
            list1.insertInfo2(temp->data.GetName(), temp->data.GetRfidTagNumber(), temp->data.GetPrice(), temp->data.getOrignalLocation(), temp->data.GetCurrentLocation());
            cout << "Item have been checkout" << endl;
        }
        temp = temp->next;
    }
    // total function
    cout << "Total: " << list1.getTotal() << endl;
}

void ItemList::PrintByRfidNumber(string rfidNumber)
{
    ItemInfoNode *temp = Head;
    while (temp)
    {
        if (temp->data.GetRfidTagNumber() == rfidNumber)
        {
            temp->data.printItem();
        }
        temp = temp->next;
    }
}

void ItemList::printByLocation(string loc)
{
    ItemInfoNode *temp = Head;
    while (temp)
    {
        if (temp->data.GetCurrentLocation() == loc)
        {
            break;
        }
        temp = temp->next;
    }
    temp->data.printItem();
}

void ItemList::cleanStore()
{
    ItemInfoNode *temp = Head;
    while (temp != NULL)
    {
        if (temp->data.GetCurrentLocation()[0] == 'c')
        {
            temp->data.setCurrentLocation(temp->data.getOrignalLocation());
            cout << "Stor have been cleaned" << endl;
        }
        temp = temp->next;
    }
}

void ItemList::removeAllPurchasedItem()
{
    ItemInfoNode *temp = Head;
    while (temp != NULL)
    {
        if (temp->data.GetCurrentLocation() == "out")
        {
            if (temp == Head)
            {
                Head = Head->next;
                Head->prev = NULL;
            }
            else if (temp == Tail)
            {
                Tail = Tail->prev;
                Tail->next = NULL;
            }
            else
            {
                ItemInfoNode *dNode = temp;
                ItemInfoNode *prevNode = temp->prev;
                prevNode->next = dNode->next;
                if (dNode->next != NULL)
                {
                    dNode->next->prev = prevNode;
                }
                length--;
            }
        }
        temp = temp->next;
    }
}
