#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include "../../HashTable/HashTable.h"

HashTable loadData(
    int size, const std::string& originalDictionaryPath,
    const std::string& newDictionaryPath
);

#endif
