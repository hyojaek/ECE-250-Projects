// define your classes here...
#include <string>

class Playlist {
    private: 
        std::string *playlist;
        std::string titleArtist; 
        int listSize; //max array size
        int currSize = 0; //current array size
        int songPosition;

    public:
        ~Playlist();
        void setMaxPlaylistSize(int n);
        void addSong(std::string ta);
        void playSong(int n);   
        void eraseSong(int n);
};

