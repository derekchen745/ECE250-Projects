#include <iostream>
#include "playlist.h"

Playlist::Playlist(const int maxSize) {
    size = maxSize;
    playlist = new std::string[size];
    }

Playlist::~Playlist() {
    delete [] playlist;
    playlist = nullptr;
}

void Playlist::addSong(std::string song) {
    if((song == "Muskrat Love;Captain and Tennille") || (song.find("My Heart Will Go On") != std::string::npos)){ 
        flag = false;
    }else{
        for (int i{0}; i < numSongs; ++i){
            if (( numSongs >= size) || (song.compare(playlist[i]) == 0)) {
                flag = false;
                break;
            }
        }  
    }

    if (flag == true) {
        playlist[numSongs] = song;
        numSongs++;
        std::cout << "success";
    }else{
        std::cout << "can not insert "<< song;
    }
    flag = true;
 }

void Playlist::playSong(int n) {
    if ((n > numSongs) || (playlist[n] == "")) {
        std::cout << "can not play " << n;
    }
    else {
        std::cout << "played " << n << " " << playlist[n];
    }
}

void Playlist:: eraseSong(int n) {
    if ((n > numSongs) || (playlist[n] == "")) {
        std::cout<< "can not erase " << n;
    } 
    else {
        playlist[n] = "";
        for(int i = n; i < numSongs; i++) {
            playlist[i] = playlist[i + 1];
            }
        playlist[numSongs] = "";
        std::cout << "success";
        numSongs += -1;
    }
}

