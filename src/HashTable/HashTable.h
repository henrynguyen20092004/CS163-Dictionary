#ifndef MAP_H
#define MAP_H

#include <QtCore>
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
    int numElements;
    int hashFunction(const QString& s);
    Node* insert(const QString& key, const std::vector<QString>& val);

   public:
    HashTable();
    ~HashTable();
    int size();
    bool contain(const QString& key);
    Node* find(const QString& key);
    void remove(const QString& key);
    void clear();
    std::vector<QString>& operator[](const QString& key);

    friend class Dictionary;
};

#endif
