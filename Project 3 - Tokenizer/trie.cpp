#include "trie.h"
#include "string"
#include <fstream>

// implement classes' member functions here...

void Trie::load(){ //no parameters
    std::string filename = "corpus.txt";
    std::ifstream file(filename);
    
    std::string word;
    while (file >> word){
        insertWord(word);
    }
    std::cout<<"success"<<std::endl;

}

bool Trie::insertWord(const std::string &word){
    TrieNode* node = root;

    for (char ch : word) { //iterate over word string
        int index = ch - 'A'; 
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index]; //sort of like curr = curr->next but for 26 pointers stored in an array
    }

    if(node->isEndOfWord == false){
        node->isEndOfWord = true;
        numOfWords++;
        return true;
    }else{
        return false;
    }
}


void Trie::numOfWordPrefix(const std::string &prefix){
    TrieNode* node = root; 

    for (char ch : prefix){
        int index = ch - 'A';
        //base case when prefix isn't found
        if(!node->children[index]){ //if there is no children with this prefix, return not found. 
            std::cout<<"not found"<<std::endl;
            return;
        }
        node = node->children[index];
    }

    int count = countNumWords(node);
    std::cout<<"count is "<<count<<std::endl;

}

void Trie::eraseWord(const std::string &word){
     if(root != nullptr && !isEmpty(root)) { 
            root = eraseWordHelper(root, word, 0);
        }
    //helper function for erase word
}


void Trie::printWord(){
    std::string currentWord, allWords;
        printWordsFromNodeInLine(root, currentWord, allWords);

        if (!allWords.empty()) {
            std::cout << allWords << std::endl;
        }

}

void Trie::spellCheck(const std::string &word){
        std::string commonPrefix;
        TrieNode* node = root;
        std::vector<std::string> suggestions;

        if(node == nullptr){
            return;
        }

        for(char ch: word){
            int index = ch - 'A'; 
            if(!node->children[index]){
                break;
                // return;
            }
            commonPrefix += ch;
            node = node->children[index];
        }

if (commonPrefix != word || !node->isEndOfWord) {
        if(!commonPrefix.empty() && node) { 
            commonPrefixWords(node, commonPrefix, suggestions);
        }
    } else {
        std::cout << "correct" << std::endl;
        return; 
    }

    if (!suggestions.empty()) {
        for (const auto& suggestion : suggestions) {
            std::cout << suggestion << " ";
        }
        std::cout << std::endl;
    } else {
        return;
    }
}


// void Trie::spellCheck(const std::string &word){ //inspired by geeks for geeks
//     std::string commonPrefix;
//     TrieNode* node = root;

//     if(node == nullptr){
//         return;
//     }

//     for(char ch: word){
//         int index = ch - 'A';
//         if(!node->children[index]){
//             break;
//         }else{
//             if(node->isEndOfWord == true){
//                 std::cout<<"correct"<<std::endl;
//                 return;
//             }
//         }
//         commonPrefix += ch;
//         node = node->children[index];
//     }
//     printSuggestions(node, commonPrefix);
//     return;

// }


void Trie::checkEmpty(){
    TrieNode* node = root; 

    if(node == nullptr){
        std::cout<<"empty 1"<<std::endl;
        return;
    }

    for(int i = 0; i<26; i++){
        if(node->children[i]!= nullptr){
            std::cout<<"empty 0"<<std::endl;
            return;
        }
    }

    std::cout<<"empty 1"<<std::endl;
    return;

}


void Trie::clear(){
    deleteNode(root);
    numOfWords = 0;
    root = nullptr;
    std::cout<<"success"<<std::endl;
    
}

void Trie::printNumWords(){
    std::cout<<"number of words is "<<numOfWords<<std::endl;
    return;
}