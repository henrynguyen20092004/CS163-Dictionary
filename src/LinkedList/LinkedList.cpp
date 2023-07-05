#include "LinkedList.h"

#include <QtCore>

void saveLinkedList(const std::string &path, Node *head) {
    QFile file(path.c_str());

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        throw std::runtime_error(path + " can't be loaded");
    }

    QTextStream fout(&file);
    QString line;

    while (head) {
        fout << head->data << '\n';
        head = head->next;
    }
}

void deleteLinkedList(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}
