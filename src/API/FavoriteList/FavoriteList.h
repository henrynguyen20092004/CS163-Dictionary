#ifndef FAVORITE_LIST_H
#define FAVORITE_LIST_H

#include "../Dictionary/KeyWithDictName/KeyWithDictName.h"

class FavoriteList {
   public:
    struct Node {
        KeyWithDictName data;
        Node *next = nullptr;
        Node(const KeyWithDictName &data) : data(data) {}
        Node(Node *next) : next(next) {}
    };

   private:
    Node *head = nullptr;
    std::string favoriteListPath = "Data/FavoriteList.txt";

    void saveList();

   public:
    FavoriteList();
    ~FavoriteList();
    bool contain(const KeyWithDictName &data);
    void addWord(const KeyWithDictName &data);
    void removeWord(const KeyWithDictName &data);
    void removeNonExistentWord(Dictionary *dictionary);
    Node *getHead();
};

#endif
