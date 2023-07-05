#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include "../../HashTable/HashTable.h"
#include "../../LinkedList/LinkedList.h"

HashTable loadData(
    int size, const std::string& originalDictionaryPath,
    const std::string& newDictionaryPath
);
Node* loadFavoriteList(const std::string& path);

#endif
