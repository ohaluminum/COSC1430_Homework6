#pragma once

#include <string>
using namespace std;

class Song {
private:
	string Title;
	string Artist;
	string Album;
	int Year;
	int PlayTime;

public:
	Song();
	Song(string Title, string Artist, string Album, int Year, int PlayTime);
	void setTitle(string Title);
	void setArtist(string Artist);
	void setAlbum(string Album);
	void setYear(int Year);
	void setPlayTime(int PlayTime);
	string getTitle();
	string getArtist();
	string getAlbum();
	int getYear();
	int getPlayTime();
	void Play();
	bool operator==(const Song& other);
};