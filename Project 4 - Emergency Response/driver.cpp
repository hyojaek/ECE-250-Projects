// include libraries here
#include <iostream>
#include <string>
#include "graph.h"


int main(){

    Graph Graph;
    
    // your code goes here...  
    std::string command;

    while(true){

        std::cin>>command;

        if(command == "insert"){
            int a;
            int b;
            double d;
            double s;
            std::cin>>a>>b>>d>>s;
            bool status = Graph.insert(a, b, d, s);
            if(status){
                std::cout<<"success"<<std::endl;
            }
        }

        if(command == "load"){
            std::string filename;
            std::cin>>filename;
            Graph.load(filename);
        }

        if(command == "traffic"){
            int a;
            int b;
            double adj;
            std::cin>>a>>b>>adj;
            bool status = Graph.traffic(a, b, adj);
            if(status){
                std::cout<<"success"<<std::endl;
            }else{
                std::cout<<"failure"<<std::endl;
            }
        }

        if(command == "update"){
            std::string filename;
            std::cin>>filename;
            Graph.update(filename);
        }

        if(command == "print"){
            int a;
            std::cin>>a;
            Graph.print(a);
        }

        if(command == "delete"){
            int a;
            std::cin>>a;
            Graph.del(a);
        }

        if(command == "path"){
            int a;
            int b;
            std::cin>>a>>b;
            Graph.path(a, b);
        }

        if(command == "lowest"){
            int a;
            int b;
            std::cin>>a>>b;
            Graph.lowest(a, b);
        }

        if(command == "exit"){
            return 0;
        }

    }
}