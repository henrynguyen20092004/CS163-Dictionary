#ifndef LOAD_DICTIONARY_H
#define LOAD_DICTIONARY_H

#include "../../HashTable/HashTable.h"

HashTable loadDictionary(
    int size, const std::string& originalDictionaryPath,
    const std::string& newDictionaryPath
);

#endif
