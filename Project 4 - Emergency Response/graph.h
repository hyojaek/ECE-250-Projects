#include <unordered_map> 
#include <limits>
// define your classes here...

class Graph {

public:

    class Edge{
        public:
        double distance;
        double speed;
        double adj;

        Edge() : distance(0), speed(0), adj(1) {};

        Edge(double d, double s, double adj) : distance(d), speed(s), adj(adj) {};

        double time() const{
            if(adj == 0){
                return std::numeric_limits<double>::infinity();
            }
            return distance/(speed*adj);
        }

    };

private:
    std::unordered_map<int, std::unordered_map<int, Edge>> map;


public:
    
    bool insert(int a, int b, double d, double s);
    void load(std::string filename);
    bool traffic(int a, int b, double adj);
    void update(std::string filename);
    void print(int a);
    void del(int a);
    void path(int a, int b);
    void lowest(int a, int b);
    void printNode(int a);
    void Dijkstras(int a, int b, std::unordered_map<int, int> &prev, std::unordered_map<int, double> &dist);
    
};