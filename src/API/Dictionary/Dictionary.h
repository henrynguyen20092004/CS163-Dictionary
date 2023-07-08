#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>

#include "../HashTable/HashTable.h"

class Dictionary {
   private:
    HashTable hashTable;

   public:
    Dictionary(
        int size, const std::string& originalDictionaryPath,
        const std::string& newDictionaryPath
    );
};

#endif
