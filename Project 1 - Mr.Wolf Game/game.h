// define your classes here...

//Player Nodes: Holds player position data
class Node {
public: 
    //store x and y values inside array like so: [x,y]
    double position[2];
    Node* next;

    Node(){
        position[0] = 0; //x value
        position[1] = 0; //y value
        next = nullptr;
    }
};


class LinkedList {

public: 
    LinkedList(){head = nullptr;}

    void spawn(double x, double y);
    void time(double t);
    void lunch();
    void num();
    void print(double d);
    void over();

private: 
    Node* head;
    int numPlayers = 0; //tracks the number of players alive or in-game. (Increment by one when SPAWM command is ran. Decrement by one when a player is eliminated after LUNCH)

    //put funtion initializations here

};