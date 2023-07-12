#include <iostream>
#include <string>
#include "playlist.h"

int main() {
    std::string input_string;
    std::string command;
    std::string song;
    int params;

    getline(std::cin,input_string);
    params = stoi(input_string.substr(2));
    Playlist playlist(params);
    std::cout << "success" << std::endl;
    
    while (!std::cin.eof()) {
        getline(std::cin, input_string);
        command = input_string.substr(0,1);

        if (command == "i") {
            song = input_string.substr(2);
            playlist.addSong(song);
        }
        
        else if (command == "p") {
            params = stoi(input_string.substr(2));
            playlist.playSong(params);
        }
        
        else if (command == "e") {
            params = stoi(input_string.substr(2));
            playlist.eraseSong(params);
        }

        std::cout << std::endl;
       
    }
    
    return 0;
}