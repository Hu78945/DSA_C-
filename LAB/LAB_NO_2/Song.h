#include <iostream>
using namespace std;

class SongRecord
{
private:
    string title, artist;
    int song_minute, song_second;

public:
    SongRecord();

    // Overloaded Constructor
    SongRecord(string title, string artist, int minute, int second);

    // getter functions
    string getTitle();
    string getArtist();
    int getSongMinuteDuration();
    int getSongSecondDuration();

    // setter functions
    void setTitle(string title);
    void setArtist(string artist);
    void setMinutes(int song_minute);
    void setSeconds(int song_second);

    // Display
    void toString();
    bool operator==(SongRecord obj1);
};