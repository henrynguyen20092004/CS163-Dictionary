#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <QString>
#include <vector>

class HashTable {
   private:
    struct Node {
        QString key;
        std::vector<QString> val;
        Node* next = nullptr;
        Node(const QString& key, const std::vector<QString>& val);
        Node(const QString& key, const std::vector<QString>& val, Node* next);
    };

    std::vector<Node*> table;
    int hashFunction(const QString& s);
    Node* find(const QString& key);
    Node* insert(const QString& key, const std::vector<QString>& val);

   public:
    HashTable(int size);
    ~HashTable();
    bool contain(const QString& key);
    void remove(const QString& key);
    void clear();
    std::vector<QString>& operator[](const QString& key);
};

#endif
