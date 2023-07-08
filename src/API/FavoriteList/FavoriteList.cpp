#include "FavoriteList.h"

#include <QFile>
#include <QTextStream>

FavoriteList::FavoriteList() {
    QFile file(favoriteListPath.c_str());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error(favoriteListPath + " can't be loaded");
    }

    QTextStream fin(&file);
    QString line;

    Node *cur, *newNode;

    while (!fin.atEnd()) {
        QString key = fin.readLine().toLower();
        newNode = new Node(key);

        if (!head) {
            head = newNode;
        } else {
            cur->next = newNode;
        }

        cur = newNode;
    }
}

void FavoriteList::addWord(const QString &data) {
    Node *newNode = new Node(data);

    if (!head || head->data > data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    for (Node *cur = head; cur->next; cur = cur->next) {
        if (cur->next->data > data) {
            newNode->next = cur->next;
            cur->next = newNode;
            saveList();
            return;
        }
    }
}

void FavoriteList::removeWord(const QString &data) {
    Node *dummy = new Node(head);

    for (Node *cur = dummy; cur->next; cur = cur->next) {
        if (cur->next->data == data) {
            Node *tmp = cur->next;
            cur->next = cur->next->next;
            head = dummy->next;
            delete tmp;
            delete dummy;
            saveList();
            return;
        }
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
        fout << cur->data << '\n';
        cur = cur->next;
    }
}

FavoriteList::~FavoriteList() {
    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}
