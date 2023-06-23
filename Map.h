#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

#define DEFAULT_SIZE 13

class Map {
   private:
    struct Node {
        std::string key;
        std::vector<std::string> val;
        Node* next = nullptr;
        Node(const std::string& key, const std::vector<std::string>& val)
            : key(key), val(val) {}
        Node(
            const std::string& key, const std::vector<std::string>& val,
            Node* next
        )
            : key(key), val(val), next(next) {}
    };
    std::vector<Node*> table;
    unsigned int numElements;
    unsigned int hashFunc(const std::string& s);

   public:
    Map() : table(DEFAULT_SIZE, nullptr), numElements(0) {}
    ~Map() { clear(); }
    bool empty();
    unsigned int size();
    Node* find(const std::string& key);
    bool contains(const std::string& key);
    Node* insert(const std::string& key, const std::vector<std::string>& val);
    void remove(const std::string& key);
    void clear();
    std::vector<std::string> listKeys();
    std::vector<std::string>& value(const std::string& key);
    std::vector<std::string>& operator[](const std::string& key);
};

#endif
