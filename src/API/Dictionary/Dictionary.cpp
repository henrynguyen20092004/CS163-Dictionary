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

std::vector<QString> Dictionary::getDefinition(const QString& key) {
    if (!hashTable.contain(key)) {
        throw key + " can't be found!";
    }

    return hashTable[key];
}
