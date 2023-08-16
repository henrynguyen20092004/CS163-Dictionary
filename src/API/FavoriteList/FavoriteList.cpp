#include "FavoriteList.h"

#include <QFile>
#include <QTextStream>

FavoriteList::FavoriteList() {
    QFile file(favoriteListPath.c_str());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error(favoriteListPath + " can't be loaded");
    }

    QTextStream fin(&file);

    Node *cur, *newNode;

    while (!fin.atEnd()) {
        QString key = fin.readLine();
        DictionaryName dictionaryName = (DictionaryName)fin.readLine().toInt();
        newNode = new Node({key, dictionaryName});

        if (!head) {
            head = newNode;
        } else {
            cur->next = newNode;
        }

        cur = newNode;
    }
}

void FavoriteList::saveList() {
    QFile file(favoriteListPath.c_str());

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        throw std::runtime_error(favoriteListPath + " can't be loaded");
    }

    QTextStream fout(&file);
    QString line;
    Node *cur = head;

    while (cur) {
        fout << cur->data.key << '\n' << cur->data.dictionaryName << '\n';
        cur = cur->next;
    }
}

bool FavoriteList::contain(const KeyWithDictName &data) {
    Node *cur = head;

    while (cur) {
        if (cur->data == data) {
            return true;
        }

        cur = cur->next;
    }

    return false;
}

void FavoriteList::addWord(const KeyWithDictName &data) {
    Node *newNode = new Node(data);

    if (!head || head->data.key > data.key) {
        newNode->next = head;
        head = newNode;
        return;
    }

    for (Node *cur = head; cur->next; cur = cur->next) {
        if (cur->next->data.key > data.key) {
            newNode->next = cur->next;
            cur->next = newNode;
            saveList();
            return;
        }
    }
}

void FavoriteList::removeWord(const KeyWithDictName &data) {
    Node *dummy = new Node(head);

    for (Node *cur = dummy; cur->next; cur = cur->next) {
        if (cur->next->data == data) {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            head = dummy->next;
            delete tmp;
            delete dummy;
            saveList();
            return;
        }
    }
}

void FavoriteList::removeNonExistentWord(Dictionary *dictionary) {
    Node *dummy = new Node(head);

    for (Node *cur = dummy; cur && cur->next; cur = cur->next) {
        if (cur->next->data.dictionaryName == dictionary->dictionaryName) {
            try {
                dictionary->getDefinition(cur->next->data.key);
            } catch (...) {
                Node *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
        }
    }

    head = dummy->next;
    delete dummy;
    saveList();
}

FavoriteList::Node *FavoriteList::getHead() { return head; }

FavoriteList::~FavoriteList() {
    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}
