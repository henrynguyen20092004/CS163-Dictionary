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

   public:
    HashTable(int size);
    ~HashTable();
    void insert(const QString& key, const std::vector<QString>& val, int index);
    std::vector<QString>& find(const QString& key);
    void update(const QString& key, const std::vector<QString>& val, int index);
    void remove(const QString& key, int index);
};

#endif