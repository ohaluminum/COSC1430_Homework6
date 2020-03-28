#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MusicLibrary.h"

//Implement a constructor taking the number of songs as an argument.
MusicLibrary::MusicLibrary(int maxsongs) 
{
	maxSongs = maxsongs;
	numSongs = 0;
	mySongs = nullptr;

	numSongsPlayList = 0;
	playList = nullptr;
}

//Implement a copy constructor.
MusicLibrary::MusicLibrary(MusicLibrary& other)
{
	this->maxSongs = other.maxSongs;
	this->numSongs = other.numSongs;

	if (numSongs == 0)
	{
		mySongs = nullptr;
	}
	else
	{
		mySongs = new Song[numSongs];
	}

	this->numSongsPlayList = other.numSongsPlayList;

	if (numSongsPlayList == 0)
	{
		playList = nullptr;
	}
	else
	{
		playList = new Song*[numSongs];
	}
}

MusicLibrary::~MusicLibrary()
{
	delete[] mySongs;
	delete[] playList;
}

int MusicLibrary::getnumSongs()
{
   return numSongs;
}

int MusicLibrary::getmaxSongs()
{
   return maxSongs;
}

int MusicLibrary::getnumSongsPlayList()
{
   return numSongsPlayList;
}

bool MusicLibrary::addSong(string title, string artist, string album, int year, int time)
{
	if (numSongs == maxSongs) {
		cout << "Could not add song to library. Library is full" << endl;
		return false;
	}
	mySongs[numSongs].setTitle(title);
	mySongs[numSongs].setArtist(artist);
	mySongs[numSongs].setAlbum(album);
	mySongs[numSongs].setYear(year);
	mySongs[numSongs].setPlayTime(time);
	numSongs++;

	return true;
}
bool MusicLibrary::addSong(Song& song)
{
	if (numSongs == maxSongs) {
		cout << "Could not add Ssong to library. Library is full" << endl;
		return false;
	}
	mySongs[numSongs] = song;
	numSongs++;

	return true;
}

void MusicLibrary::readSongsFromFile(string filename)
{
	ifstream input;
	input.open(filename);
	bool cont = true;

	if (input.is_open()) {
		string line;
		while (getline(input, line) && cont) {
			string title, artist, album;
			string s_year, s_time;
			int year;
			int time;
			istringstream inSS(line);

			getline(inSS, title, ',');
			getline(inSS, artist, ',');
			getline(inSS, album, ',');
			getline(inSS, s_year, ',');
			getline(inSS, s_time);

			year = stoi(s_year);
			time = stoi(s_time);
			cont = addSong(title, artist, album, year, time);
		}
	}	
	else {
	   cout << "could not open file " << filename << endl;
	}
}

/*
 *implement the public function 'playRandom' which plays all songs of the library (by invoking the play function of each song) in pseudo-random fashion by alternating songs from the beginning and from the end of the list, 
 *until all songs have been played. For example, if the library has 7 songs, 
 *the songs will be played in the following order: 0, 6, 1, 5, 2, 4, 3.
 */
void MusicLibrary::playRandom()
{
	for (int i = 0; i < numSongs / 2; i++)
	{
		mySongs[i].Play();
		mySongs[numSongs - 1 - i].Play();
	}

	if ((numSongs % 2) != 0)
	{
		mySongs[numSongs / 2].Play();
	}
}

bool MusicLibrary::addSongToPlayList(int pos)
{
	// implement this method
}

void MusicLibrary::playPlaylist()
{
   // implement this method
}