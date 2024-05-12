// include libraries here (STL not allowed)
#include <iostream>
#include <sstream>
#include <string>
#include "tokenize.h"

// HashMap hashMap

int main(){

    Dictionary Dictionary;

    std::string command;

    while(true){

        std::cin>>command;

        if(command == "create"){
            int size;
            std::cin>>size;
            
            Dictionary.create(size);
        }

        if(command == "insert"){
            std::string word;
            std::cin>>word;

            bool status = Dictionary.insert(word);
            if(status){
                std::cout<<"success"<<std::endl;
            }else{
                std::cout<<"failure"<<std::endl;
            }
        }

        if(command == "load"){
            std::string filename;
            std::cin>>filename;

            Dictionary.load(filename);
        }

        if(command == "tok"){
            std::string word;
            std::cin>>word;

            int token = Dictionary.tok(word);
            std::cout<<token<<std::endl;
        }

        if(command == "ret"){
            int token;
            std::cin>>token;
            std::string result;
            result = Dictionary.ret(token);
            std::cout<<result<<std::endl;
        }

        if(command == "tok_all"){
            std::string words;
            std::getline(std::cin, words);
            std::istringstream iss(words);
            std::string word;

            while(iss >> word){
                int token = Dictionary.tok(word);
                std::cout<<token<<" ";
            }
            std::cout << std::endl;

        }

        if(command == "ret_all"){
            std::string tokensInString;
            std::getline(std::cin, tokensInString);

            std::istringstream iss(tokensInString);
            int token;
            while(iss >> token){
                std::string word = Dictionary.ret(token);
                std::cout<<word<<" ";
            }
            std::cout << std::endl;

        }

        if(command == "print"){
            int k;
            std::cin>>k;

            Dictionary.print(k);
        }

        if(command == "exit"){
            return 0;
        }

    }

}