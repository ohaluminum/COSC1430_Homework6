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
	numSongsPlayList = 0;

	mySongs = new Song[maxSongs];
	playList = new Song*[maxSongs];
}

//Implement a copy constructor.
MusicLibrary::MusicLibrary(MusicLibrary& other)
{
	this->maxSongs = other.maxSongs;
	this->numSongs = other.numSongs;
	this->numSongsPlayList = other.numSongsPlayList;

	mySongs = new Song[maxSongs];
	playList = new Song*[maxSongs];
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
 *Implement the public function 'playRandom' which plays all songs of the library (by invoking the play function of each song) in pseudo-random fashion by alternating songs from the beginning and from the end of the list, 
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

/*
 *Implement the public function addSongToPlayList which stores a pointer to a song in the library in the array of Song pointer. 
 *The input to this method is an integer denoting the position of the song in the MusicLibrary.
 *If the Playlist is full, print the following error message:
 *"Could not add Song to PlayList. PlayList is full"
 *If the integer denoting the position of a song in the MusicLibrary is invalid, print the following error message:
 *"Invalid song"
 */
bool MusicLibrary::addSongToPlayList(int pos)
{
	if (numSongsPlayList == maxSongs)
	{
		cout << "Could not add Song to PlayList. PlayList is full" << endl;
		return false;
	}

	if ((pos < 0) || (pos >= numSongs))
	{
		cout << "Invalid song" << endl;
		return false;
	}

	playList[numSongsPlayList] = &mySongs[pos];
	numSongsPlayList++;

	return true;
}

//Implement the public function 'playPlaylist' which plays the songs in the playlist in the same order as the songs have been added to the playlist.
void MusicLibrary::playPlaylist()
{
	for (int i = 0; i < numSongsPlayList; i++)
	{
		playList[i]->Play();
	}
}