#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

#define DEFAULT_SIZE 10007

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
    int numElements;
    int hashFunction(const std::string& s);
    std::vector<std::string>& value(const std::string& key);

   public:
    Map();
    ~Map();
    bool isEmpty();
    int size();
    Node* find(const std::string& key);
    bool contain(const std::string& key);
    Node* insert(const std::string& key, const std::vector<std::string>& val);
    void remove(const std::string& key);
    void clear();
    std::vector<std::string>& operator[](const std::string& key);
};

#endif
