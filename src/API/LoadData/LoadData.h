#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include "../../HashTable/HashTable.h"

HashTable loadData(
    int size, const std::string& originalDictPath, const std::string& newDictPath
);

#endif
