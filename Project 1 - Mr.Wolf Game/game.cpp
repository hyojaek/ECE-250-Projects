#include "game.h" 
#include <iostream> 
#include <string> 
#include <cmath> 

void LinkedList::spawn(double x , double y){ //this is not a include statement
    //base case
    if(x <= 0 || y <= 0){ 
        std::cout<<"failure"<<std::endl;  
        return;
    }
        Node* node = new Node(); 
        node->position[0] = x; 
        node->position[1] = y;
        node->next = head; 
        head = node; 
        std::cout<<"success"<<std::endl; 
        numPlayers++; 

}

void LinkedList::time(double t){ 
    Node* temp = head; 
    Node* prev = nullptr;
    while(temp != nullptr){ //change to while loop
        double angle = atan2(temp->position[1],temp->position[0]);
        temp->position[0] -= t * cos(angle);
        temp->position[1] -= t * sin(angle); 

        if(temp->position[0] <= 0 || temp->position[1] <= 0){
            if(prev == nullptr) {
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            numPlayers--;
        } else {
            prev = temp;
            temp = temp->next;
        }
        
         //check for players out of bound or on 0,0
    }
    std::cout<<"num of players: "<<numPlayers<<std::endl;
}

void LinkedList::lunch(){

    //base case
    if(numPlayers == 0){ 
        std::cout<<"num of players: "<<numPlayers<<std::endl;
        return;
    }

    Node* temp = head; 
    Node* prev = nullptr;
    while(temp != nullptr) { 
    double x = temp->position[0];
    double y = temp->position[1];
    double distance = sqrt(x*x + y*y);    
        
        if(distance < 1){
            if(prev == nullptr) {
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            numPlayers--;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    std::cout<<"num of players: "<<numPlayers<<std::endl;

}

void LinkedList::num(){

    std::cout<<"num of players: "<<numPlayers<<std::endl;

}

void LinkedList::print(double d){

    if(numPlayers == 0){
        std::cout<<"no players found"<<std::endl;
        return;
    }
    Node* temp = head;
    int playerCount = 0;
    while(temp != nullptr){
        double x = temp->position[0];
        double y = temp->position[1];
        // double xs = x*x;
        // double ys = y*y;
        // double rs = xs + ys;
        double distance = sqrt(x*x + y*y);
        if(distance < d){
            std::cout<<x<<" "<<y<<" ";
            playerCount++;
        }
        temp = temp->next;
    }
    if(playerCount == 0){
        std::cout<<"no players found";
    }
     std::cout<<std::endl;

}

void LinkedList::over(){
    if(numPlayers > 0){
        std::cout<<"players win"<<std::endl;
    }else{
        std::cout<<"wolf wins"<<std::endl;
    }

}