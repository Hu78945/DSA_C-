#include "PlayList.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// Default Constructor
PlayList::PlayList()
{
    Array = new SongRecord[50];
    length = 0;
};
PlayList::PlayList(SongRecord R1[], int size)
{
    Array = new SongRecord[50];

    if (size <= max)
    {
        length = size;
        for (int i = 0; i < size; i++)
        {
            Array[i] = R1[i];
        }
    }
    else
    {
        string err = "Max Limit of songs in a playlist is 50";
        throw err;
    }
}

// Clone
PlayList PlayList::Clone()
{
    SongRecord cloneArray[50];
    for (int i = 0; i < 50; i++)
    {
        Array[i] = cloneArray[i];
    }
    PlayList P1(cloneArray, 50);
    return P1;
}

// Equals Function
bool PlayList::equals(PlayList P)
{
    int counter = 0;
    SongRecord P_Array[50];
    for (int i = 0; i < 50; i++)
    {
        P_Array[i] = P.Array[i];
    }
    for (int i = 0; i < 50; i++)
    {
        if (Array[i] == P_Array[i])
        {
            counter++;
        }
    }
    if (counter == 50)
    {
        return true;
    }
    return false;
}

// Helper Function
bool PlayList::CheckStrig(string s1)
{
    if (s1.empty())
    {
        return false;
    }
    return true;
}

// Get the size of Array
int PlayList::size() { return length; }

// Add a new song
void PlayList::addSong(SongRecord song, int postion)
{
    if (postion > length)
    {
        string err = "Please enter a valid postion ";
        throw err;
    }
    else
    {
        for (int i = length; i > postion; i--)
        {
            Array[i] = Array[i - 1];
        }
        Array[postion] = song;
        length++;
        cout << "Song have been added successfully" << endl;
    }
}

// Display function
void PlayList::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << Array[i].getTitle() << endl;
    }
}

// Remove a song
void PlayList::remove(int postion)
{
    if (postion < length)
    {
        for (int i = postion; i < length; i++)
        {
            Array[i] = Array[i + 1];
        }
        length--;
    }
    else
    {
        string err = "Please enter a valid index";
        throw err;
    }
}

// Get a song
SongRecord PlayList::getSong(int postion)
{
    if (CheckStrig(Array[postion].getTitle()))
    {
        return Array[postion];
    }
    else
    {
        cout << "Please engter a valid index" << endl;
        SongRecord DEFUALT = {"Default", "Default", 0, 0};
        return DEFUALT;
    }
}

// Print all songs
void PlayList::printAllSongs()
{
    int counter = 1;
    cout << "Song#  "
         << "Tile    "
         << "Artist    "
         << "Length" << endl;
    for (int i = 0; i < max; i++)
    {
        if (CheckStrig(Array[i].getTitle()))
        {
            cout << counter << ".  " << Array[i].getTitle() << "      " << Array[i].getArtist()
                 << "       " << Array[i].getSongMinuteDuration() << ":"
                 << Array[i].getSongSecondDuration() << endl;
            counter++;
        }
    }
}

// Get songs by artist
PlayList PlayList::getSongByArtist(PlayList originalList, string artist)
{
    PlayList newPlayList = {};
    SongRecord *arr = originalList.Array;
    int counter = 0;
    for (int i = 0; i < originalList.length; i++)
    {
        if (arr[i].getArtist() == artist)
        {
            newPlayList.Array[counter] = arr[i];
            counter++;
        }
    }
    newPlayList.length = counter;

    return newPlayList;
}

// to string methode
string PlayList::toString()
{
    string Play;
    std::stringstream buffer;
    for (int i = 0; i < length; i++)
    {
        buffer << i + 1 << "." << Array[i].getArtist() << "   " << Array[i].getTitle() << "   " << Array[i].getSongMinuteDuration() << ":" << Array[i].getSongSecondDuration() << endl;
    }
    Play += buffer.str();
    return Play;
}
