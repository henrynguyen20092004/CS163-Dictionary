#include "HashTable.h"

HashTable::Node::Node(
    const std::wstring& key, const std::vector<std::wstring>& val
)
    : key(key), val(val) {}

HashTable::Node::Node(
    const std::wstring& key, const std::vector<std::wstring>& val, Node* next
)
    : key(key), val(val), next(next) {}

HashTable::HashTable(int size) : table(size, nullptr), numElements(0) {}

int HashTable::hashFunction(const std::wstring& s) {
    int hash = 0, p = 29791, pow = 1, tableSize = table.size();

    for (int c : s) {
        hash = (hash + c * pow) % tableSize;
        pow = (pow * p) % tableSize;
    }

    return hash % tableSize;
}

int HashTable::size() { return numElements; }

bool HashTable::contain(const std::wstring& key) { return !find(key); }

HashTable::Node* HashTable::find(const std::wstring& key) {
    int index = hashFunction(key);

    for (Node* cur = table[index]; cur; cur = cur->next) {
        if (cur->key == key) {
            return cur;
        }
    }

    return nullptr;
}

HashTable::Node* HashTable::insert(
    const std::wstring& key, const std::vector<std::wstring>& val
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

void HashTable::remove(const std::wstring& key) {
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

std::vector<std::wstring>& HashTable::operator[](const std::wstring& key) {
    Node* result = find(key);
    return (result ? result : insert(key, std::vector<std::wstring>{}))->val;
}

HashTable::~HashTable() { clear(); }
