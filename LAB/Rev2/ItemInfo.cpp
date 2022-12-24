#include <iostream>
#include <cctype>
#include <iomanip>
#include "ItemInfo.h"
using namespace std;

ItemInfo::ItemInfo()
{
    price = 0;
}

void ItemInfo::setRfidTagNumber(string rfidTag)
{
    try
    {
        if (rfidTag.length() < 9)
        {
            string rf;
            for (int i = 0; i < rfidTag[i] != '\0'; i++)
            {
                if (rfidTag[i] >= 'A' && rfidTag[i] <= 'F')
                {
                    rf += rfidTag[i];
                }
                else if (rfidTag[i] >= 'a' && rfidTag[i] <= 'f')
                {
                    rf += rfidTag[i];
                }
                else if (rfidTag[i] == '0' || rfidTag[i] == '1' || rfidTag[i] == '2' || rfidTag[i] == '3' || rfidTag[i] == '4' || rfidTag[i] == '5' || rfidTag[i] == '6' || rfidTag[i] == '7' || rfidTag[i] == '8' || rfidTag[i] == '9')
                {
                    rf += rfidTag[i];
                }
                else
                {
                    string err = "Please Enter a valid Hexa Deciaml value";
                    throw err;
                }
            }
            this->rfidTagNumber = rf;
        }
        else
        {
            string err = "Length of the rfidTag should not be more than 9 characters";
            throw err;
        }
    }
    catch (string err)
    {
        cout << err << endl;
    }
}

string ItemInfo::getRfidTagNumber()
{
    return rfidTagNumber;
}

void ItemInfo::setOrignalLocation(string orignalLocation)
{
    try
    {
        if (orignalLocation.length() > 6)
        {
            string err = "Length of the orignal Location should not be greater than 6";
            throw err;
        }
        else if (orignalLocation.length() != 6)
        {
            string err = "Length of the orignal Loaction should be equal to  6";
            throw err;
        }
        else
        {
            if (tolower(orignalLocation[0]) != 's')
            {
                string err = "The first letter should be starting with s";
                throw err;
            }
            else
            {
                this->orignalLocation = orignalLocation;
                setCurrentLocation(orignalLocation);
            }
        }
    }
    catch (string err)
    {
        cout << err << endl;
    }
}

string ItemInfo::getOrignalLocation()
{
    return orignalLocation;
}

void ItemInfo::setCurrentLocation(string currentLocation)
{
    this->currentLocation = currentLocation;
}

string ItemInfo::getCurrentLocation()
{
    return currentLocation;
}

ItemInfo::ItemInfo(string productName, double price, string rfidTagNumber, string orignalLocation)
{
    this->productName = productName;
    setPrice(price);
    setRfidTagNumber(rfidTagNumber);
    setOrignalLocation(orignalLocation);
}

void ItemInfo::setPrice(double price)
{
    try
    {
        if (price < 0)
        {
            string err = "Please enter a valid price";
            throw err;
        }
        else
        {
            this->price = price;
        }
    }
    catch (string err)
    {
        cout << err << endl;
    }
}

void ItemInfo::Display()
{
    cout << "Name: " << productName << endl;
    cout << "Price: " << price << endl;
    cout << "RFID-Tag-Number: " << rfidTagNumber << endl;
    cout << "Orignal Location: " << orignalLocation << endl;
    cout << "Current Location: " << currentLocation << endl;
    cout << "----------------------------------------------------------" << endl;
}

// Item InfoNode

ItemInfoNode::ItemInfoNode()
{
    next = NULL;
    prev = NULL;
    data = {};
}

ItemInfoNode::ItemInfoNode(string productName, double price, string rfidTagNumber, string orignalLocation)
{
    next = NULL;
    prev = NULL;
    data = {productName, price, rfidTagNumber, orignalLocation};
}

void ItemInfoNode::setPrev(ItemInfoNode *prev)
{
    this->prev = prev;
}

void ItemInfoNode::setNext(ItemInfoNode *next)
{
    this->next = next;
}

ItemInfoNode *ItemInfoNode::getNext()
{
    return next;
}

ItemInfoNode *ItemInfoNode::getPrev()
{
    return prev;
}

// Item List

ItemList::ItemList()
{
    head = NULL;
    tail = NULL;
}

// Insert the node at the rihgt location of the list to be sorted
void ItemList::insertInfo(string name, string rfidTag, double price, string initPostion)
{
    ItemInfoNode *temp = head;
    if (head && tail)
    {
        if (stoll(rfidTag, 0, 16) < stoll(temp->data.getRfidTagNumber(), 0, 16))
        {
            ItemInfoNode *tempHead = head;
            ItemInfoNode *theHead = new ItemInfoNode(name, price, rfidTag, initPostion);
            head = theHead;
            head->prev = NULL;
            head->next = tempHead;
        }
        else
        {
            while (temp->next != NULL && stoll(temp->next->data.getRfidTagNumber(), 0, 16) < stoll(rfidTag, 0, 16))
            {
                temp = temp->getNext();
            }
            ItemInfoNode *nextNode = temp->next;
            ItemInfoNode *newNode = new ItemInfoNode(name, price, rfidTag, initPostion);
            temp->next = newNode;
            newNode->prev = temp;
            if (nextNode)
            {
                newNode->next = nextNode;
                nextNode->prev = newNode;
            }
        }
    }
    else
    {
        ItemInfoNode *newNode = new ItemInfoNode(name, price, rfidTag, initPostion);
        head = newNode;
        tail = newNode;
    }
}

// Display the entire list items
void ItemList::Display()
{
    ItemInfoNode *temp = head;
    while (temp != NULL)
    {
        temp->data.Display();
        temp = temp->next;
    }
}

// change the current location of the item
void ItemList::moveItem(string rfidTag, string source, string dest)
{
    ItemInfoNode *temp = head;
    while (temp != NULL)
    {
        if (temp->data.getRfidTagNumber() == rfidTag)
        {
            if (temp->data.getOrignalLocation() == source)
            {
                temp->data.setCurrentLocation(dest);
                break;
            }
        }
        temp = temp->next;
    }
}

// clean the store and takes any wrong location and put it in correct location on the shelf
void ItemList::cleanStore()
{
    ItemInfoNode *temp = head;
    while (temp != NULL)
    {
        if (temp->data.getCurrentLocation()[0] == 'c')
        {
            string ogLoc = temp->data.getOrignalLocation();
            temp->data.setCurrentLocation(ogLoc);
        }
        temp = temp->next;
    }
}

// takes all of the cart item and mark their current location to out
void ItemList::checkOut(string cartNumber)
{
    ItemInfoNode *temp = head;
    while (temp != NULL)
    {
        if (temp->data.getCurrentLocation() == cartNumber)
        {
            temp->data.setCurrentLocation("out");
        }
        temp = temp->next;
    }
}

// Remove all the items whose current location is out
void ItemList::RemoveAllPurchased()
{
    ItemInfoNode *temp = head;
    while (temp != NULL)
    {
        if (temp->data.getCurrentLocation() == "out")
        {
            ItemInfoNode *previous = temp->prev;
            if (temp->next)
            {
                previous->next = temp->next;
                temp->next->prev = previous;
            }
            previous->next = temp->next;
        }
        temp = temp->next;
    }
}

void ItemList::printByLocation(string location)
{
    ItemInfoNode *temp = head;
    while (temp != NULL)
    {
        if (temp->data.getOrignalLocation() == location)
        {
            temp->data.Display();
        }
        temp = temp->next;
    }
}

void ItemList::PrintByRfidNumber(string rfi)
{
    ItemInfoNode *temp = head;
    while (temp != NULL)
    {
        if (temp->data.getRfidTagNumber() == rfi)
        {
            temp->data.Display();
        }
        temp = temp->next;
    }
}

void DepartmentStore::Menue()
{
    char choice;
    ItemList list = {};

    while (choice != 'Q')
    {

        cout << "-------------------------Menu----------------------------" << endl;
        cout << "I(Insert and item into the list)" << endl;
        cout << "M(Move and item in the store)" << endl;
        cout << "P(Print all the item into store)" << endl;
        cout << "L(CheckOut)" << endl;
        cout << "C(Clean the store)" << endl;
        cout << "U(Update the record system)" << endl;
        cout << "R(Print by Rfid Number)" << endl;
        cout << "Q(Exit the program)" << endl;
        cout << "-----------------------------------------------------------" << endl;
        // Get the input from th user
        cout << "Enter Your Choice: ";
        cin >> choice;
        toupper(choice);

        switch (choice)
        {
        case 'I': // ok
        {
            try
            {
                system("cls");

                string name, rfidTag, initPostion;
                double price;
                cout << "--------------------------------------" << endl;
                cout << "Enter the name of product: ";
                cin >> name;
                cout << "Enter the RFID Tag Number: ";
                cin >> rfidTag;
                cout << "Enter price of the product: ";
                cin >> price;
                cout << "Enter the initial postioin: ";
                cin >> initPostion;
                list.insertInfo(name, rfidTag, price, initPostion);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }

            break;
        }

        case 'P':
        {
            system("cls");
            list.Display();
            break;
        }

        case 'M':
        {
            system("cls");
            string rfidTagNumber, source, destination;
            cout << "--------------------------------------" << endl;
            cout << "Enter the RFID Tag Number: ";
            cin >> rfidTagNumber;
            cout << "Enter source of the prodcut: ";
            cin >> source;
            cout << "Enter the destination of the procut" << endl;
            cin >> destination;
            list.moveItem(rfidTagNumber, source, destination);
        }

        case 'L': // ok
        {
            system("cls");
            string cart;
            cout << "Enter the cart Number: " << endl;
            cin >> cart;
            list.checkOut(cart);
        }

        case 'C':
        {
            system("cls");
            list.cleanStore();
            break;
        }

        case 'R': // ok
        {
            system("cls");
            cout << "Enter the RFID_TAG_NUMBER: ";
            string rfi;
            cin >> rfi;
            list.PrintByRfidNumber(rfi);
            break;
        }

        case 'U': // ok
        {
            system("cls");
            list.RemoveAllPurchased();
            break;
        }

        case 'Q':
        {
            exit(0);
        }

        default:
            break;
        }
    }
}
