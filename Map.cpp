#include "Map.h"

unsigned int Map::hashFunc(const std::string& s) {
    unsigned int hash = 0;
    for (const char c : s) {
        hash += static_cast<unsigned int>(c);
    }
    return hash;
}

bool Map::empty() { return numElements == 0; }

unsigned int Map::size() { return numElements; }

Map::Node* Map::find(const std::string& key) {
    unsigned int index = hashFunc(key) % table.size();
    Node* list = table[index];

    while (list) {
        if (list->key == key) {
            return list;
        }
        list = list->next;
    }

    return table[index];
}

bool Map::contains(const std::string& key) {
    Node* res = find(key);

    if (!res) {
        return false;
    } else {
        return true;
    }
}

Map::Node* Map::insert(
    const std::string& key, const std::vector<std::string>& val
) {
    unsigned int index = hashFunc(key) % table.size();
    if (!table[index]) {
        table[index] = new Node(key, val);
        ++numElements;
    } else {
        if (table[index]->key == key) {
            return table[index];
        }
        Node* list = table[index];
        while (list->next) {
            if (list->key == key) {
                return list;
            }
            list = list->next;
        }
        list->next = new Node(key, val);
        ++numElements;
    }
    return table[index];
}

void Map::remove(const std::string& key) {
    unsigned int index = hashFunc(key) % table.size();
    Node* list = table[index];
    Node* prev = nullptr;

    while (list) {
        if (list->key == key) {
            if (prev) {
                prev->next = list->next;
            } else {
                table[index] = table[index]->next;
            }
            --numElements;
            delete list;
            list = nullptr;
            return;
        }
        prev = list;
        list = list->next;
    }
}

void Map::clear() {
    for (Node*& list : table) {
        while (list) {
            Node* toDeleted = list;
            list = list->next;
            delete toDeleted;
            toDeleted = nullptr;
        }
    }
    numElements = 0;
}

std::vector<std::string> Map::listKeys() {
    std::vector<std::string> result;
    for (Node*& list : table) {
        while (list) {
            result.push_back(list->key);
            list = list->next;
        }
    }
    return result;
}

std::vector<std::string>& Map::value(const std::string& key) {
    Node* res = find(key);
    if (res) {
        return res->val;
    } else {
        return (*insert(key, std::vector<std::string>{})).val;
    }
}

std::vector<std::string>& Map::operator[](const std::string& key) {
    return this->value(key);
}
