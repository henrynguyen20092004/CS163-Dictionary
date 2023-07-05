#include "AddToFavoriteList.h"

#include "../../GlobalVar/GlobalVar.h"

void addDataToFavoriteList(const std::wstring &data, Node *&favoriteList) {
    Node *newNode = new Node(data);

    if (!favoriteList || favoriteList->data > newNode->data) {
        newNode->next = favoriteList;
        favoriteList = newNode;
        return;
    }

    Node *cur = favoriteList;

    while (cur->next) {
        if (cur->next->data > newNode->data) {
            newNode->next = cur->next->next;
            cur->next = newNode;
            return;
        }

        cur = cur->next;
    }
}

void addToFavoriteList(const std::wstring &data) {
    Node *favoriteList = GlobalVar::data.favoriteList;
    addDataToFavoriteList(data, favoriteList);
    saveLinkedList("Data/FavoriteList.txt", favoriteList);
}
