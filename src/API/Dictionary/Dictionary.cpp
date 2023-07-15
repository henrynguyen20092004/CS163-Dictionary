#include "Dictionary.h"

#include <QFile>
#include <QTextStream>
#include <stdexcept>

#include "../HashTable/HashFunction/HashFunction.h"
#include "LoadDictionary/LoadDictionary.h"

Dictionary::Dictionary(
    int size, const std::string &originalDictionaryPath,
    const std::string &newDictionaryPath
)
    : size(size),
      hashTable(size),
      originalDictionaryPath(originalDictionaryPath),
      newDictionaryPath(newDictionaryPath) {
    loadOriginalDictionary(originalDictionaryPath, hashTable);
    loadNewDictionary(newDictionaryPath, hashTable);
}

void Dictionary::resetNewDictionaryFile() {
    QFile file(newDictionaryPath.c_str());

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        throw std::runtime_error(newDictionaryPath + " can't be loaded");
    }
}

std::vector<QString> Dictionary::getDefinition(const QString &key) {
    return hashTable.find(key);
}

void Dictionary::resetDictionary() {
    hashTable.clear();
    resetNewDictionaryFile();
    loadOriginalDictionary(originalDictionaryPath, hashTable);
}

void Dictionary::saveData(int index, const QString &key, SaveMode saveMode) {
    QFile file(newDictionaryPath.c_str());

    if (!file.open(
            QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append
        )) {
        throw std::runtime_error(newDictionaryPath + " can't be loaded");
    }

    QTextStream fout(&file);
    fout << '\n' << index << '\n' << (char)saveMode << '\n' << key << '\n';
}

void Dictionary::removeWordFromDictionary(const QString &key) {
    int index = hashFunction(key, size);
    hashTable.remove(key, index);
    saveData(index, key, REMOVE);
}
