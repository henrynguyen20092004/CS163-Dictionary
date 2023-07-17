#include "Dictionary.h"

#include <QFile>
#include <QTextStream>
#include <stdexcept>

#include "../HashTable/HashFunction/HashFunction.h"
#include "../SubstringCheck/ProcessString/ProcessString.h"
#include "../SubstringCheck/SubstringCheck.h"
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
    const QString &key, const std::vector<QString> &val
) {
    int index = hashFunction(key, size);

    if (!hashTable.find(key, index).empty()) {
        throw std::invalid_argument("Word already exists!");
    }

    hashTable.insert(key, val, index);
    saveData(ADD, index, key, val);
}

std::vector<QString> Dictionary::getDefinition(const QString &key) {
    std::vector<QString> definition =
        hashTable.find(key, hashFunction(key, size));

    if (!definition.empty()) {
        return definition;
    }

    throw std::invalid_argument("Word can't be found!");
}

std::vector<QString> Dictionary::getKeywordFromSubDefinition(
    const QString &subDefinition
) {
    QString newSubDefinition = processString(subDefinition);
    CharacterTable characterTable(newSubDefinition);

    return hashTable.findKeywordIf([&](const QString &definition) {
        return substringCheck(
            processString(definition), newSubDefinition, characterTable
        );
    });
}

void Dictionary::editDefinitionOfWord(
    const QString &key, std::vector<QString> &val
) {
    int index = hashFunction(key, size);

    hashTable.update(key, val, index);
    saveData(UPDATE, index, key, val);
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

bool Dictionary::checkWordExist(
    const QString &word,
    const std::vector<std::pair<QString, std::vector<QString>>> &listOfWord
) {
    for (int i = 0; i < listOfWord.size(); ++i) {
        if (listOfWord[i].first == word) {
            return true;
        }
    }
    return false;
}

bool Dictionary::checkChoose(
    const std::vector<std::pair<QString, std::vector<QString>>> &listOfWord,
    int option
) {
    return listOfWord[option].second[0] == listOfWord[0].second[0];
}

void Dictionary::getRandomWordList(
    std::vector<std::pair<QString, std::vector<QString>>> &listOfWord
) {
    int countRandomNumber = 4;

    while (countRandomNumber && size > 0) {
        int keyIndex = hashTable.randomIndex(size - 1);

        std::pair<QString, std::vector<QString>> word;
        word = hashTable.randomWord(keyIndex);

        if (word.first == "" || checkWordExist(word.first, listOfWord)) {
            continue;
        }

        listOfWord.push_back(word);

        --countRandomNumber;
    }
}

bool Dictionary::randomWordWithFourDefinitions() {
    std::vector<std::pair<QString, std::vector<QString>>> listOfWord;

    getRandomWordList(listOfWord);

    int option = 1;

    return checkChoose(listOfWord, option);
}
