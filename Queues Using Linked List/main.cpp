#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    // fist type mostly used in opearting systems
    // for examplen java jvm allow multi threadinng so it allow priority upon threads

    // for examplewe take three priorityies
    // elements ----> A  B  C  D  E  F  G  H  I  J
    // priority ----> 1  1  2  3  2  1  2  3  2  2
    // Samaller the number hiher the priority or larger the number smaller the priority

    // For the implememtation we have only three priorities so we wil take three queues

    Queue q1 = {};
    Queue q2 = {};
    Queue q3 = {};

    // so depending upon the priority they will be placedin the q accordingly
    // whenever we ar delting we are deleing from the highest priority and if it is empty we will move to the other queue

    // iterative program to test the priority
    int choice;
    char item;
    while (choice != 4)
    {
        cout << "elements ----> A  B  C  D  E  F  G  H  I  J" << endl;
        cout << "priority ----> 1  1  2  3  2  1  2  3  2  2" << endl;
        cout << "Press 1 to add a character" << endl;
        cout << "Press 2 to delete" << endl;
        cout << "Press 3 to Display" << endl;
        cout << "Press 4 to exit" << endl;

        // Get the input from the user
        cout << "Enter your choice: ";
        cin >> choice;
        // Switch case statments
        if (choice == 1)
        {
            system("cls");
            cout << "Please enter the character: ";
            cin >> item;
            switch (item)
            {
            case 'A':
            {
                q1.enqueu(item);
                break;
            }
            case 'B':
            {
                q1.enqueu(item);
                break;
            }
            case 'C':
            {
                q2.enqueu(item);
                break;
            }
            case 'D':
            {
                q3.enqueu(item);
                break;
            }
            case 'E':
            {
                q2.enqueu(item);
                break;
            }
            case 'F':
            {
                q1.enqueu(item);
                break;
            }
            case 'G':
            {
                q2.enqueu(item);
                break;
            }
            case 'H':
            {
                q3.enqueu(item);
                break;
            }
            case 'I':
            {
                q2.enqueu(item);
                break;
            }
            case 'J':
            {
                q2.enqueu(item);
                break;
            }

            default:
                break;
            }
        }
        else if (choice == 2)
        {
            if (!q1.isEmpty())
            {
                q1.dequeu();
            }
            else if (!q2.isEmpty())
            {
                q2.dequeu();
            }
            else if (!q3.isEmpty())
            {
                q3.dequeu();
            }
            else
            {
                cout << "All the queue is empty" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "----------------------------------------------------------------" << endl;
            cout << "Priority Queue: ";
            q1.Display();
            q2.Display();
            q3.Display();
            cout << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
        else if (choice == 4)
        {
            break;
        }
    }

    return 0;
}