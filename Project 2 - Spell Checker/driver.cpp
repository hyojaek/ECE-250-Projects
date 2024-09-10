// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include <fstream>
#include "trie.h"


int main(){

Trie Trie;

std::string command;

while(true){
    std::cin>>command;
    if(command == "load"){
        Trie.load();
    }

    if(command == "i"){
        std::string word;
        std::cin>>word;
        
        bool status = Trie.insertWord(word);

        if(status == true){
            std::cout<<"success"<<std::endl;
        }else{
            std::cout<<"failure"<<std::endl;
        }

    }

    if(command == "c"){
        std::string prefix;
        std::cin>>prefix;

        Trie.numOfWordPrefix(prefix);

    }

    if(command == "e"){
        std::string word;
        std::cin>>word;

        Trie.eraseWord(word);

    }

    if(command == "p"){

        Trie.printWord();

    }

    if(command == "spellcheck"){
        std::string word;
        std::cin>>word;

        Trie.spellCheck(word);

    }   

    if(command == "empty"){
        
        Trie.checkEmpty();

    }

    if(command == "clear"){

        Trie.clear();

    }

    if(command == "size"){

        Trie.printNumWords();

    }

    if(command == "exit"){

        // Trie.exit();
        return 0;

    }
}

    
    // your code goes here...  

}