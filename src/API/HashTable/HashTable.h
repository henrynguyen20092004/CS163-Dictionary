#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <QString>
#include <vector>

class HashTable {
   private:
    struct Node {
        QString key;
        std::vector<QString> val;
        Node* next;
        Node(const QString& key, const std::vector<QString>& val, Node* next);
    };

    std::vector<Node*> table;

   public:
    HashTable(int size);
    ~HashTable();
    void insert(const QString& key, const std::vector<QString>& val, int index);
    std::vector<QString> find(const QString& key, int index);
    std::vector<QString> findKeywordIf(
        std::function<bool(const QString&)> definitionCheckFunction
    );
    void update(const QString& key, const std::vector<QString>& val, int index);
    void remove(const QString& key, int index);
    void clear();

    int randomIndex(int size);
    std::pair<QString, std::vector<QString>> randomWord(int index);
};

#endif
