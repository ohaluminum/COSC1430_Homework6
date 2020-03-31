# COSC1430_Homework6

The purpose of this assignment is to develop the code for managing a Music Library.

Class Song

    The class will have the following private attributes:

    Title (string)
    Artist (string)
    Album (string)
    PlayTime (integer)
    Year (integer)
  
    It will also have the following public member functions:

    -Default constructor setting the playtime to 0 and year to 0.
    -A constructor using Title, Artist, Album, Year, and PlayTime as arguments
    -Accessors and mutators for all private attributes
    -A void function 'Play' that will print out the information about the song in the following format (provided)
    -Playing *Title* by  *Artist*  *playtime* seconds
    -A comparison operator == that uses title, artist and album (but not year and playtime) for comparing two songs.
    -Implement the missing functions using the template provided.

Class MusicLibrary

    MusicLibrary has the following private attributes

    int maxSongs
    int numSongs
    Song * mySongs
    int numSongsPlayList
    Song** playList;
    
    **Note that mySongs is a pointer that will be used to initialize a dynamic array of songs. You need to handle this dynamic array correctly (e.g. shallow copies, memory deallocation etc.)
    **PlayList is a dynamic array of pointers to Songs in the mySongs array.

    The class also includes the following public member functions:

    -Bool function addSong taking title, artist, album, playtime, year (provided)
    -ReadSongsFromFile (provided)
    -Some accessors (provided)
    
    This class is partially implemented. Complete the following:

    -Implement a constructor taking the number of songs as an argument
    -Implement a copy constructor
    
    -Implement the public function 'playRandom' which plays all songs of the library (by invoking the play function of each song) in pseudo-random fashion by alternating songs from the beginning and from the end of the list, until all songs have been played. 
        
        For example, if the library has 7 songs, the songs will be played in the following order: 0, 6, 1, 5, 2, 4, 3
     
    -Implement the public function addSongToPlayList which stores a pointer to a song in the library in the array of Song pointer. 
    
        The input to this method is an integer denoting the position of the song in the MusicLibrary.
        
        If the Playlist is full, print the following error message:
        "Could not add Song to PlayList. PlayList is full"

        If the integer denoting the position of a song in the MusicLibrary is invalid, print the following error message:
        "Invalid song"
        
     -Implement the public function 'playPlaylist' which plays the songs in the playlist in the same order as the songs have been added to the playlist.
