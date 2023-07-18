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
    std::vector<QString> definition =
        hashTable.find(key, hashFunction(key, size));

    if (!definition.empty()) {
        return definition;
    }

    throw std::invalid_argument("Word can't be found!");
}

void Dictionary::saveData(
    SaveMode saveMode, int index, const QString &key,
    const std::vector<QString> &val
) {
    QFile file(newDictionaryPath.c_str());

    if (!file.open(
            QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append
        )) {
        throw std::runtime_error(newDictionaryPath + " can't be loaded");
    }

    QTextStream fout(&file);
    fout << '\n' << index << '\n' << (char)saveMode << '\n' << key << '\n';

    if (saveMode != 'r') {
        for (const QString &definition : val) {
            fout << definition << '\n';
        }
    }
}

void Dictionary::addWordToDictionary(
    const QString &key, std::vector<QString> &val
) {
    int index = hashFunction(key, size);

    if (!hashTable.find(key, index).empty()) {
        throw std::invalid_argument("Word already exists!");
    }

    hashTable.insert(key, val, index);
    saveData(ADD, index, key, val);
}

void Dictionary::removeWordFromDictionary(const QString &key) {
    int index = hashFunction(key, size);
    hashTable.remove(key, index);
    saveData(REMOVE, index, key);
}

void Dictionary::resetDictionary() {
    hashTable.clear();
    resetNewDictionaryFile();
    loadOriginalDictionary(originalDictionaryPath, hashTable);
}
