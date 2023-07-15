#include "Dictionary.h"

#include "LoadDictionary/LoadDictionary.h"

Dictionary::Dictionary(
    int size, const std::string& originalDictionaryPath,
    const std::string& newDictionaryPath, DictionaryName dictionaryName
)
    : hashTable(size),
      originalDictionaryPath(originalDictionaryPath),
      newDictionaryPath(newDictionaryPath),
      dictionaryName(dictionaryName) {
    loadOriginalDictionary(originalDictionaryPath, hashTable);
    loadNewDictionary(newDictionaryPath, hashTable);
}

std::vector<QString> Dictionary::getDefinition(const QString& key) {
    return hashTable.find(key);
}

void Dictionary::reloadDictionary() {
    hashTable.clear();
    loadOriginalDictionary(originalDictionaryPath, hashTable);
}
