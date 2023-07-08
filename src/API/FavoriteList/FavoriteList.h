#ifndef FAVORITE_LIST_H
#define FAVORITE_LIST_H

#include <QString>
#include <string>

class FavoriteList {
   private:
    struct Node {
        QString data;
        Node *next = nullptr;
        Node(const QString &data) : data(data) {}
        Node(Node *next) : next(next) {}
    };

    std::string favoriteListPath = "Data/FavoriteList.txt";
    Node *head;

   public:
    FavoriteList();
    void addWord(const QString &data);
    void removeWord(const QString &data);
    void saveList();
    ~FavoriteList();
};

#endif
