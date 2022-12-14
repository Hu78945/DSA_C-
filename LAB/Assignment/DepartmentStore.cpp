#include <iostream>
#include "DepartmentStore.h"
using namespace std;

void DepartmentStore::Menue()
{
    char choice;
    ItemList list = {};

    while (choice != 'Q')
    {

        cout << "-------------------------Menue----------------------------" << endl;
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

        case 'P': // ok
        {
            system("cls");
            list.Display();
            break;
        }

        case 'M': // ok
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
            bool res = list.moveItem(rfidTagNumber, source, destination);
            if (res)
                cout << "Prodcut have been moved successfully" << endl;
            else
                cout << "Product Do not exist" << endl;
            break;
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
            list.removeAllPurchasedItem();
            break;
        }

        case 'Q':
        {
            exit(0);
            break;
        }

        default:
            break;
        }
    }
}
