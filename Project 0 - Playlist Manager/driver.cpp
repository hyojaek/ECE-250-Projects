// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "playlist.h"


int main(int argc, char *argv[]){
// your code goes here...
Playlist playlist;
while(true){
    std::string command;
    std::cin>>command;

    if(command == "done"){
        
        return 0;
    }

    //question: Can we assume that the user is only going to run the "m" command once? 
    if(command == "m"){
        int n;
        std::cin>>n; //I might need to take these inputs in
        playlist.setMaxPlaylistSize(n);

    }

    if(command == "i"){
        std::string ta;
        // std::cin>>ta;
        getline(std::cin, ta);
        playlist.addSong(ta);
    }

    if(command == "p"){
        int n;
        std::cin>>n;
        playlist.playSong(n);

    }

    if(command == "e"){
        int n;
        std::cin>>n;
        playlist.eraseSong(n);
    }
}
}