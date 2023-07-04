#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class HashTable {
   private:
    struct Node {
        std::wstring key;
        std::vector<std::wstring> val;
        Node* next = nullptr;
        Node(const std::wstring& key, const std::vector<std::wstring>& val);
        Node(
            const std::wstring& key, const std::vector<std::wstring>& val,
            Node* next
        );
    };
    std::vector<Node*> table;
    int numElements;
    int hashFunction(const std::wstring& s);
    Node* insert(const std::wstring& key, const std::vector<std::wstring>& val);

   public:
    HashTable(int size);
    ~HashTable();
    int size();
    bool contain(const std::wstring& key);
    Node* find(const std::wstring& key);
    void remove(const std::wstring& key);
    void clear();
    std::vector<std::wstring>& operator[](const std::wstring& key);
};

#endif
