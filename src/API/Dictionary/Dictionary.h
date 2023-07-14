#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QString>
#include <string>

#include "../HashTable/HashTable.h"

enum DictionaryName {
    EE,
    EV,
    VE,
    SLANG,
    EMOJI,
};

class Dictionary {
   private:
    HashTable hashTable;
    std::string originalDictionaryPath, newDictionaryPath;

   public:
    DictionaryName dictionaryName;

    Dictionary(
        int size, const std::string& originalDictionaryPath,
        const std::string& newDictionaryPath, DictionaryName dictionaryName
    );
    std::vector<QString> getDefinition(const QString& key);
    void reloadDictionary();
};

#endif
