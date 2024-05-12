// define your classes here...

#include <iostream>
#include <string>
#include <vector>

class Trie {
public:
    void load();
    bool insertWord(const std::string& word);
    void numOfWordPrefix(const std::string& prefix);
    void eraseWord(const std::string& word);
    void printWord();
    void spellCheck(const std::string& word);
    void checkEmpty();
    void clear();
    void printNumWords();
    // void exit();

    Trie() : root(new TrieNode()) {}

    ~Trie() { clear(); }

private:

    int numOfWords{0};

    class TrieNode {
    public:
        static const int ALPHA_SIZE = 26;
        TrieNode* children[ALPHA_SIZE];
        bool isEndOfWord;

        TrieNode() : isEndOfWord(false) {
            for (int i = 0; i < ALPHA_SIZE; ++i) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    void deleteNode(TrieNode* node){
        if(node == nullptr){
            return;
        }

        for(int i = 0; i<26; i++){
            if(node->children[i]){
                deleteNode(node->children[i]); 
                node->children[i] = nullptr;
            }
        }
        delete node;
    }

    void commonPrefixWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions) {
        if (node == nullptr) {
            return;
        }
        if (node->isEndOfWord) {
            suggestions.push_back(prefix); 
        }
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                char nextChar = 'A' + i; 
                commonPrefixWords(node->children[i], prefix + nextChar, suggestions);
            }
        }
    }

        // void printSuggestions(TrieNode* node, const std::string& prefix) {
        // if (node == nullptr) {
        //     return;
        // }
        // if (node->isEndOfWord) {
        //     std::cout << prefix << std::endl;
        // }
        // for (int i = 0; i < 26; ++i) {
        //     if (node->children[i] != nullptr) {
        //         char nextChar = 'A' + i; 
        //         printSuggestions(node->children[i], prefix + nextChar);
        //     }
        // }
        // }
    

    int countNumWords(TrieNode* node){
        if(node == nullptr){
            return 0;
        }
        
        int count = node->isEndOfWord ? 1 : 0;
        for(int i = 0; i<26; i++){//26 = num of char in alphabet
            count += countNumWords(node->children[i]);
        }
        return count;
    }

    void printWordsFromNodeInLine(TrieNode* node, std::string& currentWord, std::string& allWords) {
        if (!node) return;
        

        // if this node marks the end of a word, add it to allWords
        if (node->isEndOfWord) {
            allWords += (allWords.empty() ? "" : " ") + currentWord; 
        }

        // iterate through children
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {

                char currentChar = 'A' + i; 
                currentWord.push_back(currentChar);
                
                printWordsFromNodeInLine(node->children[i], currentWord, allWords);
                
                currentWord.pop_back(); //backtrack
            }
        }
    }

    bool isEmpty(TrieNode* root){

    for (int i = 0; i < 26; i++){
        if (root->children[i]){
            return false;
        }     
    }
    return true;
}

    TrieNode* eraseWordHelper(TrieNode* node, const std::string& word, std::string::size_type depth) { //inspired by geeks for geeks: https://www.geeksforgeeks.org/trie-delete/
        if (node == nullptr) {
            // if node doesn't exist, do nothing
            std::cout<<"failure"<<std::endl;
            return nullptr;
        }


        if (depth == word.length()) {
            //at end of word
            if (node->isEndOfWord) {
                node->isEndOfWord = false; 
                numOfWords--;
                std::cout<<"success"<<std::endl;
            }
            // if node has no children, delete
            if (isEmpty(node)) {
                delete node;
                return nullptr;
            }
            return node;
        }

        int index = word[depth] - 'A'; 
        node->children[index] = eraseWordHelper(node->children[index], word, depth + 1);

        if(root == node){
            return root;
        }

        if (isEmpty(node) && !node->isEndOfWord) {
            delete node;
            return nullptr;
        }

        return node;
    }
    
    
};
