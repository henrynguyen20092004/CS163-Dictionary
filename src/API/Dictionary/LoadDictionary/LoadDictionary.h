#ifndef LOAD_DICTIONARY_H
#define LOAD_DICTIONARY_H

#include <string>

#include "../../HashTable/HashTable.h"

void loadOriginalDictionary(
    const std::string& originalDictionaryPath, HashTable& dictionary
);
void loadNewDictionary(
    const std::string& newDictionaryPath, HashTable& dictionary
);

#endif
