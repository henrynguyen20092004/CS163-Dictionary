#ifndef DATA_H
#define DATA_H

#include "../API/loadDictionary/loadDictionary.h"
#include "../FavoriteList/FavoriteList.h"

struct Data {
    HashTable DictEE = loadDictionary(10007, "Data/OriginalEE.txt", "Data/NewEE.txt");
    HashTable DictEV = loadDictionary(5099, "Data/OriginalEV.txt", "Data/NewEV.txt");
    HashTable DictVE = loadDictionary(5309, "Data/OriginalVE.txt", "Data/NewVE.txt");
    HashTable DictSlang =
        loadDictionary(947, "Data/OriginalSlang.txt", "Data/NewSlang.txt");
    HashTable DictEmoji =
        loadDictionary(41, "Data/OriginalEmoji.txt", "Data/NewEmoji.txt");
    FavoriteList favoriteList;
};

#endif
