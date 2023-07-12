#include <iostream>

class Playlist {

    // class variables
	private:
	int size;  
    std::string *playlist;
    int numSongs = 0;
    bool flag = true;


    // class functions
    public:
    Playlist(const int maxSize);
    ~Playlist();

    //Command i: adds the given song at the end of the playlist
    void addSong(std::string song);
    
    //Command p: plays song at position n
    void playSong(int n);
    
    //Command e: erases song at position n
    void eraseSong(int n);

};