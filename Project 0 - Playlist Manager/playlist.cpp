#include "playlist.h"
#include <iostream>
#include <string>
// implement classes' member functions here...


void Playlist::setMaxPlaylistSize(int n){
    listSize = n;
    playlist = new std::string[listSize];
    std::cout<<"success"<<std::endl;
}

void Playlist::addSong(std::string ta){
    //getting rid of space at the beginning of string
    titleArtist = ta.substr(1);

    //checking if the list is full
    if(listSize<=currSize){
        std::cout<<"can not insert "<<titleArtist<<std::endl;
        return;
    }


    //perform check for restricted entry 
    std::string delimiter = ";";
    std::string restrictedSong = ta.substr(1, ta.find(delimiter));
    if(titleArtist == "Baby;Justin Bieber" || restrictedSong == "My Heart Will Go On;"){
        std::cout<<"can not insert"<<ta<<std::endl;
        return;
    }

    //perform check for overlapping songs
    int n = listSize;
    for(int i = 0; i < n; i++){
        if(playlist[i] == titleArtist){
            std::cout<<"can not insert"<<ta<<std::endl;
            return;
        }
    }   
    playlist[currSize] = titleArtist;
    currSize++;
    std::cout<<"success"<<std::endl;
}

void Playlist::playSong(int n){
    //increment n since currSize is always one greater than n (because currSize != index position)
    if(currSize < n+1){
        std::cout<<"can not play "<<n<<std::endl;
        return; 
    }
    std::cout<<"played "<<n<<" "<<playlist[n]<<std::endl;

}

void Playlist::eraseSong(int n){
    if(listSize<n || currSize<n){
        std::cout<<"can not erase n"<<std::endl;
        return;
    }

    for(int i = n; i<currSize; i++ ){
        //setting each value in the array starting from n (the position of the erased song) to the value at index n+1. (sliding each value down one index in the array)
        playlist[i] = playlist[i+1];
    }
    //delete value at the last index of array that wasn't moved by the for loop
    // playlist[currSize];

    std::cout<<"success"<<std::endl;

    //decrease current size since one title;artist was deleted
    currSize--;
}

Playlist::~Playlist(){
    delete[] playlist;
}