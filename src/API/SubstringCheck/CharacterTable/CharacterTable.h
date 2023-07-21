#ifndef CHARACTER_TABLE_H
#define CHARACTER_TABLE_H

#include <QString>
#include <vector>

class CharacterTable {
   private:
    struct Node {
        QChar character;
        int lastIndex;
        Node* next;
        Node(QChar character, int lastIndex, Node* next);
        ~Node();
    };

    int strSize;
    std::vector<Node*> table;

   public:
    CharacterTable(const QString& str);
    ~CharacterTable();
    void insert(QChar character, int lastIndex);
    int find(QChar character) const;
};

#endif
