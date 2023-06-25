#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

class Map {
   private:
    struct Node {
        std::string key;
        std::vector<std::string> val;
        Node* next = nullptr;
        Node(const std::string& key, const std::vector<std::string>& val);
        Node(
            const std::string& key, const std::vector<std::string>& val,
            Node* next
        );
    };
    std::vector<Node*> table;
    int numElements;
    int hashFunction(const std::string& s);

   public:
    Map();
    ~Map();
    int size();
    bool isEmpty();
    bool contain(const std::string& key);
    Node* find(const std::string& key);
    Node* insert(const std::string& key, const std::vector<std::string>& val);
    void remove(const std::string& key);
    void clear();
    std::vector<std::string>& operator[](const std::string& key);
};

#endif
