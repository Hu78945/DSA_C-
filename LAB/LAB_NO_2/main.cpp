#include <iostream>
#include "PlayList.h"
using namespace std;

int main()
{
    // // Make object of SongRecord
    // SongRecord R1 = {"Hello", "Me", 35, 30};
    // SongRecord R2 = {"Hello1", "Me1", 34, 30};
    // SongRecord R3 = {"Hello2", "Me2", 33, 30};
    // SongRecord R4 = {"Hello3", "mooo", 32, 30};
    // SongRecord R5 = {"Hello4", "mooo", 42, 30};
    // SongRecord R6 = {"Behzad", "mooo", 12, 30};

    // // Make and empty PlayList
    // SongRecord P1[5];
    // P1[0] = R1;
    // P1[1] = R2;
    // P1[2] = R3;
    // P1[3] = R4;
    // P1[4] = R5;

    // PlayList l1(P1, 5);
    // l1.addSong(R6, 1);
    // l1.printAllSongs();
    // PlayList l2 = PlayList::getSongByArtist(l1, "mooo");
    // cout << "-------------------------------------" << endl;
    // l2.printAllSongs();
    // string test = l1.toString();
    // cout << "---------------------------" << endl;
    // cout << test << endl;

    // Menue
    // Create an enmpty PlayList
    PlayList Play1 = {};
    char choice;
    while (choice != 'q')
    {
        // Menue
        cout << "A)"
             << "   "
             << "Add Song" << endl;
        cout << "B)"
             << "   "
             << "Print Songs by Artist" << endl;
        cout << "G)"
             << "   "
             << "Get Song" << endl;

        cout << "R)"
             << "   "
             << "Remove Song" << endl;
        cout << "P)"
             << "   "
             << "Print All Songs" << endl;
        cout << "S)"
             << "   "
             << "Size" << endl;
        cout << "Q)"
             << "   "
             << "Quit" << endl;

        // Take Input
        cout << "Select a menu option: ";
        cin >> choice;
        cout << endl;

        // Switch case Statment
        switch (tolower(choice))
        {
        case 'a':
        {
            string title, artist;
            int minute, second, postion;
            // enter title
            cout << "Enter the Song Title: ";
            cin >> title;

            // enter artist
            cout << "Enter the Song Artist: ";
            cin >> artist;

            // enter song length in minute
            cout << "Enter the Song length(minute): ";
            cin >> minute;

            // enter song length in seconds
            cout << "Enter the Song length(seconds): ";
            cin >> second;

            // enter title
            cout << "Enter the postion: ";
            cin >> postion;

            // Make a song Record
            SongRecord song = {title, artist, minute, second};
            // add to playlist
            Play1.addSong(song, postion);
            break;
        }
        case 'b':
        {
            string artist;
            cout << "Enter the artist: ";
            cin >> artist;
            cout << endl;
            PlayList p1 = PlayList::getSongByArtist(Play1, artist);
            p1.printAllSongs();
            break;
        }

        case 'g':
        {
            int pos1;
            cout << "Enter the postion: ";
            cin >> pos1;
            cout << "Error is here" << endl;

            SongRecord R = Play1.getSong(pos1);
            R.toString();
            break;
        }

        case 'r':
        {
            int pos;
            cout << "Enter the postion: ";
            cin >> pos;
            Play1.remove(pos);
            break;
        }

        case 'p':
        {
            Play1.printAllSongs();
            break;
        }
        case 's':
        {
            cout << "PlayList have " << Play1.size() << " songs" << endl;
        }
        case 'q':
        {
            cout << "Quiting the programe" << endl;
            break;
        }

        default:
            break;
        }
    }
}