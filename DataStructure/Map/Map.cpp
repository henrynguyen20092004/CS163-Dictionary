#include "Map.h"

int Map::hashFunction(const std::string& s) {
    int sum = 0;

    for (const char c : s) {
        sum += c;
    }

    return sum;
}

Map::Map() : table(DEFAULT_SIZE, nullptr), numElements(0) {}

Map::~Map() { clear(); }

bool Map::isEmpty() { return !numElements; }

int Map::size() { return numElements; }

Map::Node* Map::find(const std::string& key) {
    int index = hashFunction(key) % table.size();

    for (Node* cur = table[index]; cur; cur = cur->next) {
        if (cur->key == key) {
            return cur;
        }
    }

    return nullptr;
}

bool Map::contain(const std::string& key) { return !find(key); }

Map::Node* Map::insert(
    const std::string& key, const std::vector<std::string>& val
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

void Map::remove(const std::string& key) {
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

void Map::clear() {
    for (Node*& cur : table) {
        while (cur) {
            Node* toDeleted = cur;
            cur = cur->next;
            delete toDeleted;
        }
    }

    numElements = 0;
}

std::vector<std::string>& Map::value(const std::string& key) {
    Node* result = find(key);
    return (result ? result : insert(key, std::vector<std::string>{}))->val;
}

std::vector<std::string>& Map::operator[](const std::string& key) {
    return value(key);
}
