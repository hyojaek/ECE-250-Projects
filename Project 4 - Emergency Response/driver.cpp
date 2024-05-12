// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "game.h"


int main(){

LinkedList LinkedList;

std::string command;

    
while(true){
    std::cin>>command;
    if(command == "SPAWN"){
        double x;
        double y;

        std::cin>>x;
        std::cin>>y;
        LinkedList.spawn(x,y);

    }


    if(command == "TIME"){

        double t;

        std::cin>>t;
        LinkedList.time(t);

    }


    if(command == "LUNCH"){
        LinkedList.lunch();

    }


    if(command == "NUM"){
        LinkedList.num();

    }


    if(command == "PRT"){

        double d;
        std::cin>>d;
        LinkedList.print(d);

    }


    if(command == "OVER"){
        LinkedList.over();
        return 0;
    }


 }    // your code goes here...  
}