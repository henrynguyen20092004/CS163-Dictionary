#include "Dictionary.h"

#include "LoadDictionary/LoadDictionary.h"

Dictionary::Dictionary(
    int size, const std::string& originalDictionaryPath,
    const std::string& newDictionaryPath
)
    : hashTable(size) {
    loadOriginalDictionary(originalDictionaryPath, hashTable);
    loadNewDictionary(newDictionaryPath, hashTable);
}
