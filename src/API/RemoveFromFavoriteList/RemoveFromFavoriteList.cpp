#include "RemoveFromFavoriteList.h"

#include "../../GlobalVar/GlobalVar.h"

void removeData(const std::wstring &removeData, Node *favoriteList) {
    if (!favoriteList) {
        return;
    }

    Node *cur = favoriteList, *prev = nullptr;

    while (cur) {
        if (cur->data == removeData) {
            if (!prev) {
                favoriteList = favoriteList->next;
            } else {
                prev->next = cur->next;
            }

            delete cur;
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

void removeFromFavoriteList(const std::wstring &data) {
    Node *favoriteList = GlobalVar::data.favoriteList;
    removeData(data, favoriteList);
    saveLinkedList("Data/FavoriteList.txt", favoriteList);
}
