#include "Song.h"
#include <iostream>
using namespace std;
class PlayList
{
private:
    static int size1;
    int length;
    int max = 50;

public:
    SongRecord *Array;
    // Default Constructor
    PlayList();
    PlayList(SongRecord R1[], int size);
    // Clone
    PlayList Clone();
    // Equals Function
    bool equals(PlayList P);
    // Helper Function
    bool CheckStrig(string s1);
    // Get the size of Array
    int size();
    // add a new song
    void addSong(SongRecord song, int postion);
    // display function
    void display();
    // remove a song
    void remove(int postion);
    // Get a song
    SongRecord getSong(int postion);
    // print all songs
    void printAllSongs();
    // Get song by artist
    static PlayList getSongByArtist(PlayList originalList, string artist);
    // to string function
    string toString();
};