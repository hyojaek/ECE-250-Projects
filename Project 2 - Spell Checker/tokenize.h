#include <vector>
#include <forward_list>
#include <string>
#include <utility>

class Dictionary {
public:
    class HashMap {
    private:
        int capacity;
        int numPairs;
        std::forward_list<std::pair<std::string, int>>* table;

    public:
        HashMap(int capacity);

        ~HashMap();

        void rehash();

        bool exists(const std::string &word);

        unsigned hash(const std::string & str);

        void insert(const std::string &word, int token);

        int getToken(const std::string &word);

        void print(int k);



    };

private:
    std::vector<std::string> wordVec;
    HashMap* hashMap;

public:
    Dictionary() : hashMap(nullptr){
        wordVec.push_back("");
    };
    ~Dictionary(){
        delete hashMap;
    }

    void create(int size);

    bool insert(const std::string &word);

    void load(std::string filename);

    int tok(const std::string &word);
    
    std::string ret(unsigned token);

    // void tok_all(const std::vector<std::string>& words);
    
    void ret_all();

    void print(int k);

};
