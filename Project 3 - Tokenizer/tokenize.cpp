#include "tokenize.h"
#include <iostream>
#include <string>
#include <fstream>
#include <forward_list>

// implement classes' member functions here...

Dictionary::HashMap::HashMap(int initCapacity) : capacity(initCapacity), numPairs(0) {
    table = new std::forward_list<std::pair<std::string, int>>[capacity];
}

Dictionary::HashMap::~HashMap() {
    delete[] table;
}


bool isAlpha(const std::string& word) {
    for (char ch : word) {
        if (!std::isalpha(ch)) {
            return false;
        }
    }
    return true;
}

void Dictionary::HashMap::rehash(){

    int oldCapacity = capacity;
    capacity *= 2;
    
    std::forward_list<std::pair<std::string, int>>* newTable = new std::forward_list<std::pair<std::string, int>>[capacity];

    for(int i = 0; i < oldCapacity; i++){ 
        for(const auto& entry: table[i]){
            unsigned newIndex = hash(entry.first); 
            newTable[newIndex].push_front(entry);
        }
    }

    delete[] table;
    table = newTable;

}

bool Dictionary::HashMap::exists(const std::string &word) {
    int index = hash(word);
    for (const auto &entry : table[index]) {
        if (entry.first == word) {
            return true;
        }
    }
    return false;
}

unsigned Dictionary::HashMap::hash(const std::string & str){
    unsigned ans = 0; 

    for(auto it = str.begin(); it != str.end(); ++it){
        ans = ans * 29 + *it;
    }
        return ans%capacity;
}

void Dictionary::HashMap::insert(const std::string &word, int token){
    double loadFactor = (numPairs+1.0)/capacity;
    if(loadFactor >= 0.8){
        rehash();
    }

    if(!exists(word)){
        int index = hash(word);
        table[index].push_front(std::make_pair(word, token));
        numPairs++;
    }
}

int Dictionary::HashMap::getToken(const std::string &word){
    int index = hash(word);

    for(const auto& entry : table[index]){
        if(entry.first == word){
            return entry.second;
        }
    }

    return -1;

}

void Dictionary::HashMap::print(int k) {

    if (k >= 0 && k < capacity) {
        auto& chain = table[k]; 
        if (!chain.empty()) {
            for (const auto& entry : chain) {
                std::cout << entry.first << " "; 
            }
            std::cout << std::endl;
        }
    }
}

void Dictionary::create(int size){
    if(hashMap != nullptr){
        delete hashMap;
    }
    hashMap = new HashMap(size);
    std::cout<<"success"<<std::endl;
}

bool Dictionary::insert(const std::string &word) {
    if (!isAlpha(word) || hashMap->exists(word)) {  
        return false;  
    }

    int token = wordVec.size();
    wordVec.push_back(word); 
    hashMap->insert(word, token); 

    return true; 
}

void Dictionary::load(std::string filename){
    std::ifstream file(filename);
    bool inserted = false;

    std::string word;
    while(file >> word){
        if(insert(word)){
            inserted = true;
        }
    } 
    if(inserted){
        std::cout<<"success"<<std::endl;   
    }else{
        std::cout<<"failure"<<std::endl;
    }

}

int Dictionary::tok(const std::string &word){
 
    if(hashMap == nullptr){
        return -1;
    }

    int result = hashMap->getToken(word);
    return result;

    }

std::string Dictionary::ret(unsigned token){
    if(token >= 0 && token < wordVec.size() && !wordVec[token].empty()){
        return wordVec[token];
    }else{
        std::string na; 
        na = "N/A";
        return na;
    }
    
}

void Dictionary::print(int k){
    hashMap->print(k);
}