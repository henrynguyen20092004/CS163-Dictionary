#include "HashTable.h"

#include "../RandomIndex/RandomIndex.h"
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
    const std::function<bool(const QString&, bool&)>& checkFunction,
    bool checkKeyword
) {
    std::vector<QString> keywords;
    bool isExactMatch = false;
    int exactMatchIndex = -1;

    for (Node* head : table) {
        for (; head; head = head->next) {
            if (!checkKeyword) {
                for (QString& definition : head->val) {
                    if (checkFunction(definition, isExactMatch)) {
                        if (isExactMatch) {
                            exactMatchIndex = keywords.size();
                            isExactMatch = false;
                        }

                        keywords.push_back(head->key);
                        break;
                    }
                }
            } else if (checkFunction(head->key, isExactMatch)) {
                if (isExactMatch) {
                    exactMatchIndex = keywords.size();
                    isExactMatch = false;
                }

                keywords.push_back(head->key);
            }
        }
    }

    if (exactMatchIndex != -1) {
        QString exactMatch = keywords[exactMatchIndex];

        for (int i = exactMatchIndex; i > 0; i--) {
            keywords[i] = keywords[i - 1];
        }

        keywords[0] = exactMatch;
    }

    std::sort(keywords.begin() + (exactMatchIndex != -1), keywords.end());
    return keywords;
}

Word HashTable::randomWord(int index) {
    Node* cur = table[index];

    if (!cur) {
        return {"", ""};
    }

    int lengthOfLinkedList = 0;

    while (cur->next) {
        ++lengthOfLinkedList;
        cur = cur->next;
    }

    cur = table[index];

    for (int keyIndex = randomIndex(lengthOfLinkedList); keyIndex; --keyIndex) {
        cur = cur->next;
    }

    int definitionIndex = randomIndex(cur->val.size());
    return {cur->key, cur->val[definitionIndex]};
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
