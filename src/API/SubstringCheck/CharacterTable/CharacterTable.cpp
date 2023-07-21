#include "CharacterTable.h"

#define DEFAULT_SIZE 37

CharacterTable::Node::Node(QChar character, int lastIndex, Node* next)
    : character(character), lastIndex(lastIndex), next(next) {}

CharacterTable::Node::~Node() { delete next; }

CharacterTable::CharacterTable(const QString& str)
    : table(DEFAULT_SIZE, nullptr), strSize(str.size()) {
    for (int i = strSize - 1; i >= 0; i--) {
        if (find(str[i]) == strSize + 1) {
            insert(str[i], strSize - i);
        }
    }
}

void CharacterTable::insert(QChar character, int lastIndex) {
    int index = character.unicode() % DEFAULT_SIZE;
    table[index] = new Node(character, lastIndex, table[index]);
}

int CharacterTable::find(QChar character) const {
    int index = character.unicode() % DEFAULT_SIZE;

    for (Node* head = table[index]; head; head = head->next) {
        if (head->character == character) {
            return head->lastIndex;
        }
    }

    return strSize + 1;
}

CharacterTable::~CharacterTable() {
    for (Node* head : table) {
        delete head;
    }
}
