#include <iostream>
#include "Song.h"

//Default constructor setting the playtime to 0 and year to 0.
Song::Song()
{
	Title = "";
	Artist = "";
	Album = "";
	Year = 0;
	PlayTime = 0;
}

//A constructor using Title, Artist, Album, Year, and PlayTime as arguments.
Song::Song(string Title, string Artist, string Album, int Year, int PlayTime)
{
	this->Title = Title;
	this->Artist = Artist;
	this->Album = Album;
	this->Year = Year;
	this->PlayTime = PlayTime;
}

//Accessors and mutators for all private attributes.
void Song::setTitle(string Title)
{
	this->Title = Title;
}

void Song::setArtist(string Artist)
{
	this->Artist = Artist;
}

void Song::setAlbum(string Album)
{
	this->Album = Album;
}

void Song::setYear(int Year)
{
	this->Year = Year;
}

void Song::setPlayTime(int PlayTime)
{
	this->PlayTime = PlayTime;
}

string Song::getTitle()
{
	return Title;
}

string Song::getArtist()
{
	return Artist;
}

string Song::getAlbum()
{
	return Album;
}

int Song::getYear()
{
	return Year;
}

int Song::getPlayTime()
{
	return PlayTime;
}

//A void function 'Play' that will print out the information about the song in the following format (provided)
void Song::Play()
{
	cout << "Playing "<< Title << " by " << Artist << " " << PlayTime << " seconds" << endl;
}

//A comparison operator == that uses title, artist and album (but not year and playtime) for comparing two songs.
bool Song::operator==(const Song& other)
{
	if (Title.compare(other.Title) == 0)
	{
		if (Artist.compare(other.Artist) == 0)
		{
			if (Album.compare(other.Album) == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

