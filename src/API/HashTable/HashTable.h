#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <QString>
#include <vector>

using Word = std::pair<QString, QString>;

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
        const std::function<bool(const QString&, bool&)>& checkFunction,
        bool checkKeyword = true
    );
    Word randomWord(int index);
    void update(const QString& key, const std::vector<QString>& val, int index);
    void remove(const QString& key, int index);
    void clear();
};

#endif
