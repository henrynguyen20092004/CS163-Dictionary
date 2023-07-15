#include "Dictionary.h"

#include <QFile>
#include <QTextStream>
#include <stdexcept>

#include "../HashTable/HashFunction/HashFunction.h"
#include "LoadDictionary/LoadDictionary.h"

Dictionary::Dictionary(
    int size, const std::string &originalDictionaryPath,
    const std::string &newDictionaryPath, DictionaryName dictionaryName
)
    : size(size),
      hashTable(size),
      originalDictionaryPath(originalDictionaryPath),
      newDictionaryPath(newDictionaryPath),
      dictionaryName(dictionaryName) {
    loadOriginalDictionary(originalDictionaryPath, hashTable);
    loadNewDictionary(newDictionaryPath, hashTable);
}

std::vector<QString> Dictionary::getDefinition(const QString &key) {
    return hashTable.find(key);
}

void Dictionary::reloadDictionary() {
    hashTable.clear();
    loadOriginalDictionary(originalDictionaryPath, hashTable);
}

void Dictionary::removeWordFromDictionary(
    const QString &key, const std::string &newDictionaryPath
) {
    std::vector<QString> b = hashTable.find(key);
    saveData(key, newDictionaryPath);
}

void Dictionary::saveData(
    const QString &key, const std::string &newDictionaryPath
) {
    QFile file(newDictionaryPath.c_str());

    if (!file.open(
            QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append
        )) {
        throw std::runtime_error(newDictionaryPath + " can't be loaded");
    }

    QTextStream fout(&file);
    QString line;

    int wordIndex = hashFunction(key, size);

    fout << '\n' << wordIndex << '\n';
    fout << "r" << '\n';
    fout << key << '\n';
}
