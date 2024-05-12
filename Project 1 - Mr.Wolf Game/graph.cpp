#include "graph.h"
#include <limits>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <float.h>
#include <queue>
#include <vector>
#include <unordered_map>
#include <limits>
#include <functional> 

// implement classes' member functions here...

bool Graph::insert(int a, int b, double d, double s){

    if(map[a].find(b)!= map[a].end()){
        map[a][b].distance = d;
        map[b][a].distance = d;
        map[a][b].speed = s;
        map[b][a].speed = s;
        return true;
    }

    map[a][b] = Edge(d, s, 1.0);
    map[b][a] = Edge(d, s, 1.0);
    return true;

}

void Graph::load(std::string filename){
    std::ifstream file(filename);

    int a;
    int b;
    double d;
    double s;
    while(file >> a >> b >> d >> s){
        insert(a, b, d, s);
    }
    std::cout<<"success"<<std::endl;
    return;
}

bool Graph::traffic(int a, int b, double adj){
    if(map[a].find(b) == map[a].end()){
        return false;
    }else{
        map[a][b].adj = adj;
        map[b][a].adj = adj;
        return true;
    }
}

void Graph::update(std::string filename){
    bool isUpdated = false;
    std::ifstream file(filename);
    int a;
    int b;
    double adj;
    while(file >> a >> b >> adj){
        if(traffic(a, b, adj)){
            isUpdated = false;
        }
    }

    if(isUpdated){
        std::cout<<"success"<<std::endl;
    }else{
        std::cout<<"failure"<<std::endl;
    }
}

void Graph::print(int a){
    if(map.find(a) == map.end()){
        std::cout<<"failure"<<std::endl;
    }else if (map[a].empty()){
        std::cout<<"failure"<<std::endl;
    }else{
        for(auto& iter:map[a]){
        std::cout<<iter.first<<" ";
    };
    std::cout<<std::endl;
    }
}

void Graph::del(int a){
    
    if(map.find(a) == map.end()){
        std::cout << "failure" << std::endl;
        return;
    } else {
        for(auto& iter : map[a]){
            map[iter.first].erase(a);
        }
        map.erase(a);
        std::cout << "success" << std::endl;
        return;
    }
}

void Graph::path(int a, int b){
    std::unordered_map<int, int> prev;
    std::unordered_map<int, double> dist;
    if(map.find(a) == map.end()){
        std::cout<<"failure"<<std::endl;
        return;
    }
    if(map.find(b) == map.end()){
        std::cout<<"failure"<<std::endl;
        return;
    }
    Dijkstras(a, b, prev, dist);

    if(prev.find(b) == prev.end()){
        std::cout<<"failure"<<std::endl;
        return;
    }
    std::vector<int> path;
    for (int current = b; current != a; current = prev[current]) {
        path.push_back(current);
    }
    path.push_back(a);

    for(auto it = path.rbegin(); it != path.rend(); ++it) {
        if(it != path.rbegin()) std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
    return;
}

void Graph::lowest(int a, int b){
    double lowest_cost = DBL_MAX;
    std::unordered_map<int, int> prev;
    std::unordered_map<int, double> dist;
    if(map.find(a)==map.end()){
        std::cout << "failure" << std::endl;
        return;
    }
    Dijkstras(a, b, prev, dist);
		
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(3);
    if(dist[b] != std::numeric_limits<double>::infinity() && dist[b] != 0.0){
        lowest_cost = dist[b];
        std::cout << lowest_cost << std::endl;
    }else{
        std::cout << "failure" << std::endl;
        return;
    }
}

void Graph::Dijkstras(int a, int b, std::unordered_map<int, int> &prev, std::unordered_map<int, double> &dist) {
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
    std::unordered_map<int, bool> visited;
    for (const auto& node : map) {
        dist[node.first] = std::numeric_limits<double>::infinity();
        visited[node.first] = false;
    }

    dist[a] = 0.0; 
    pq.push({0.0, a}); 

    while (!pq.empty()) {
        int current = pq.top().second; 
        pq.pop(); 

        if (visited[current]) continue; 
        visited[current] = true; 

        for (const auto& edge : map[current]) {
            int neighbor = edge.first;
            double time = edge.second.time(); 

            if (dist[current] + time < dist[neighbor]) {
                dist[neighbor] = dist[current] + time; 
                prev[neighbor] = current; 
                pq.push({dist[neighbor], neighbor}); 
            }
        }
    }
}