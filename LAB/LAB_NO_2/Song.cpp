#include <iostream>
#include "Song.h"
using namespace std;

SongRecord::SongRecord()
{
    // set the int var to zero
    song_minute = 0;
    song_second = 0;
};
// Overloaded Constructor
SongRecord::SongRecord(string title, string artist, int minute, int second)
{
    this->title = title;
    this->artist = artist;
    song_minute = minute;
    song_second = second;
}
// getter functions
string SongRecord::getTitle() { return title; }
string SongRecord::getArtist() { return artist; }
int SongRecord::getSongMinuteDuration() { return song_minute; }
int SongRecord::getSongSecondDuration() { return song_second; }

// setter functions
void SongRecord::setTitle(string title) { this->title = title; }
void SongRecord::setArtist(string artist) { this->artist = artist; }
void SongRecord::setMinutes(int song_minute)
{
    if (song_minute > 59 || song_minute < 0)
    {
        string err = "Please enter a value between 0 and 59";
        throw err;
    }
    else
    {
        this->song_minute = song_minute;
    }
}
void SongRecord::setSeconds(int song_second)
{
    if (song_second > 59 || song_second < 0)
    {
        string err = "Please enter a value between 0 and 59";
        throw err;
    }
    else
    {
        this->song_second = song_second;
    }
}

// Display
void SongRecord::toString()
{
    cout << "Title: " << this->title << endl;
    cout << "Artist: " << this->artist << endl;
    cout << "Song Duration in Minute: " << this->song_minute << endl;
    cout << "Song Duration in Seconds: " << this->song_second << endl;
}

bool SongRecord::operator==(SongRecord obj1)
{
    if (this->title == obj1.title && this->artist == obj1.artist && this->song_minute == obj1.song_minute && this->song_second == obj1.song_second)
    {
        return true;
    }
    return false;
}
