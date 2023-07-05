#ifndef DATA_H
#define DATA_H

#include "../API/LoadData/LoadData.h"

struct Data {
    HashTable DictEE = loadData(10007, "Data/OriginalEE.txt", "Data/NewEE.txt");
    HashTable DictEV = loadData(5099, "Data/OriginalEV.txt", "Data/NewEV.txt");
    HashTable DictVE = loadData(5309, "Data/OriginalVE.txt", "Data/NewVE.txt");
    HashTable DictSlang =
        loadData(947, "Data/OriginalSlang.txt", "Data/NewSlang.txt");
    HashTable DictEmoji =
        loadData(41, "Data/OriginalEmoji.txt", "Data/NewEmoji.txt");
    Node *favoriteList = loadFavoriteList("Data/FavoriteList.txt");

    ~Data() { deleteLinkedList(favoriteList); };
};

#endif
