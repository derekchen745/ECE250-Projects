#include <iostream>

class Song {
    private:
    std::string title;
    std::string artist;

    public:
    Song(std::string title, std::string artist);
    ~Song();
    std::string getTitle();
    void setTitle();
    std::string getArtist();
    void setArtist();

};