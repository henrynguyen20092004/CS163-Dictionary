#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QString>
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
    std::vector<QString> getDefinition(const QString& key);
};

#endif
