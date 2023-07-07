#include "HashTable.h"

HashTable::Node::Node(const QString& key, const std::vector<QString>& val)
    : key(key), val(val) {}

HashTable::Node::Node(
    const QString& key, const std::vector<QString>& val, Node* next
)
    : key(key), val(val), next(next) {}

HashTable::HashTable() : numElements(0) {}

int HashTable::hashFunction(const QString& s) {
    int hash = 0, p = 29791, pow = 1, tableSize = table.size();

    for (QChar c : s) {
        hash = (hash + (c.unicode()) * pow) % tableSize;
        pow = (pow * p) % tableSize;
    }

    return hash % tableSize;
}

int HashTable::size() { return numElements; }

bool HashTable::contain(const QString& key) { return !find(key); }

HashTable::Node* HashTable::find(const QString& key) {
    int index = hashFunction(key);

    for (Node* cur = table[index]; cur; cur = cur->next) {
        if (cur->key == key) {
            return cur;
        }
    }

    return nullptr;
}

HashTable::Node* HashTable::insert(
    const QString& key, const std::vector<QString>& val
) {
    int index = hashFunction(key);
    Node* newHead = new Node(key, val);

    if (table[index]) {
        newHead->next = table[index];
    }

    table[index] = newHead;
    ++numElements;
    return newHead;
}

void HashTable::remove(const QString& key) {
    int index = hashFunction(key);
    Node *cur = table[index], *prev = nullptr;

    while (cur) {
        if (cur->key == key) {
            if (prev) {
                prev->next = cur->next;
            } else {
                table[index] = table[index]->next;
            }

            --numElements;
            delete cur;
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

void HashTable::clear() {
    for (Node*& head : table) {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    numElements = 0;
}

std::vector<QString>& HashTable::operator[](const QString& key) {
    Node* result = find(key);
    return (result ? result : insert(key, std::vector<QString>{}))->val;
}

HashTable::~HashTable() { clear(); }
