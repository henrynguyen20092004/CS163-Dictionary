#include "HashTable.h"

#include "HashFunction/HashFunction.h"

HashTable::Node::Node(const QString& key, const std::vector<QString>& val)
    : key(key), val(val) {}

HashTable::Node::Node(
    const QString& key, const std::vector<QString>& val, Node* next
)
    : key(key), val(val), next(next) {}

HashTable::HashTable(int size) : table(size, nullptr) {}

void HashTable::insert(
    const QString& key, const std::vector<QString>& val, int index
) {
    Node* newHead = new Node(key, val);

    if (table[index]) {
        newHead->next = table[index];
    }

    table[index] = newHead;
}

std::vector<QString>& HashTable::find(const QString& key) {
    int index = hashFunction(key, table.size());

    for (Node* cur = table[index]; cur; cur = cur->next) {
        if (cur->key == key) {
            return cur->val;
        }
    }

    throw std::invalid_argument("Key can't be found!");
}

void HashTable::update(
    const QString& key, const std::vector<QString>& val, int index
) {
    find(key) = val;
}

void HashTable::remove(const QString& key, int index) {
    Node *cur = table[index], *prev = nullptr;

    while (cur) {
        if (cur->key == key) {
            if (prev) {
                prev->next = cur->next;
            } else {
                table[index] = table[index]->next;
            }

            delete cur;
            return;
        }

        prev = cur;
        cur = cur->next;
    }

    throw std::invalid_argument("Key can't be found!");
}

void HashTable::clear() {
    for (Node*& head : table) {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
}

HashTable::~HashTable() { clear(); }
