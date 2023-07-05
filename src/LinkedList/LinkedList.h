#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

struct Node {
    std::wstring data;
    Node *next = nullptr;
    Node(const std::wstring &data) : data(data) {}
};

void saveLinkedList(const std::string &path, Node *head);
void deleteLinkedList(Node *head);

#endif
