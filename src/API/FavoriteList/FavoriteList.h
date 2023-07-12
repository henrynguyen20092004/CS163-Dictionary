#ifndef FAVORITE_LIST_H
#define FAVORITE_LIST_H

#include <QString>
#include <string>

class FavoriteList {
   private:
    std::string favoriteListPath = "Data/FavoriteList.txt";

   public:
    struct Node {
        QString data;
        Node *next = nullptr;
        Node(const QString &data) : data(data) {}
        Node(Node *next) : next(next) {}
    };

    FavoriteList();
    Node *head;
    void addWord(const QString &data);
    void removeWord(const QString &data);
    bool contain(const QString &data);
    void saveList();
    ~FavoriteList();
};

#endif
