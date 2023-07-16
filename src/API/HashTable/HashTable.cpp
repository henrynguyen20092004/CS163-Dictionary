#include "HashTable.h"

#include "HashFunction/HashFunction.h"

HashTable::Node::Node(
    const QString& key, const std::vector<QString>& val, Node* next
)
    : key(key), val(val), next(next) {}

HashTable::HashTable(int size) : table(size, nullptr) {}

void HashTable::insert(
    const QString& key, const std::vector<QString>& val, int index
) {
    table[index] = new Node(key, val, table[index]);
}

std::vector<QString> HashTable::find(const QString& key, int index) {
    for (Node* cur = table[index]; cur; cur = cur->next) {
        if (cur->key == key) {
            return cur->val;
        }
    }

    return {};
}

std::vector<QString> HashTable::findKeywordIf(
    std::function<bool(const QString&)> definitionCheckFunction
) {
    std::vector<QString> keywords;

    for (Node* head : table) {
        for (; head; head = head->next) {
            for (const QString& definition : head->val) {
                if (definitionCheckFunction(definition)) {
                    keywords.push_back(head->key);
                    break;
                }
            }
        }
    }

    return keywords;
}

void HashTable::update(
    const QString& key, const std::vector<QString>& val, int index
) {
    for (Node* cur = table[index]; cur; cur = cur->next) {
        if (cur->key == key) {
            cur->val = val;
            return;
        }
    }

    throw std::invalid_argument("Word can't be found!");
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

    throw std::invalid_argument("Word can't be found!");
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

int randomIndex(int size) { return 1 + rand() % (size); }

std::pair<QString, std::vector<QString>> HashTable::random(int index) {
    Node* curKey = table[index];

    QString key = "";
    std::vector<QString> val;

    if (curKey == nullptr) {
        return make_pair(key, val);
    }

    int lengthOfLinkedList = 0;
    while (curKey->next) {
        ++lengthOfLinkedList;
    }

    int keyIndex = randomIndex(lengthOfLinkedList + 1);
    curKey = table[index];
    while (keyIndex != 1) {
        curKey = curKey->next;
        --keyIndex;
    }

    key = curKey->key;
    val = curKey->val;

    return make_pair(key, val);
}
