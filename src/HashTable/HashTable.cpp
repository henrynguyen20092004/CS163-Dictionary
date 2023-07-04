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
    int hash = 0, p = 29791, m = table.size(), pow = 1;

    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * pow) % m;
        pow = (pow * p) % m;
    }

    return hash;
}

int HashTable::size() { return numElements; }

bool HashTable::isEmpty() { return !numElements; }

bool HashTable::contain(const std::wstring& key) { return !find(key); }

HashTable::Node* HashTable::find(const std::wstring& key) {
    int index = hashFunction(key) % table.size();

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
    int index = hashFunction(key) % table.size();

    if (!table[index]) {
        table[index] = new Node(key, val);
        ++numElements;
        return table[index];
    } else {
        if (table[index]->key == key) {
            return table[index];
        }

        Node* cur = table[index];

        for (; cur->next; cur = cur->next) {
            if (cur->key == key) {
                return cur;
            }
        }

        cur->next = new Node(key, val);
        ++numElements;
        return cur->next;
    }
}

void HashTable::remove(const std::wstring& key) {
    int index = hashFunction(key) % table.size();
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
