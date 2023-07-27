#include "Dictionary.h"

#include <QFile>
#include <QTextStream>
#include <stdexcept>

#include "../HashTable/HashFunction/HashFunction.h"
#include "../RandomIndex/RandomIndex.h"
#include "../SubstringCheck/ProcessString/ProcessString.h"
#include "../SubstringCheck/SubstringCheck.h"
#include "LoadDictionary/LoadDictionary.h"

#define OPTION_COUNT 4

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

bool Dictionary::checkWordExistInWordList(
    const QString &word, const std::vector<Word> &wordList
) {
    for (int i = 0; i < wordList.size(); ++i) {
        if (wordList[i].first == word) {
            return true;
        }
    }

    return false;
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

RandomList Dictionary::getFourRandomWords() {
    std::vector<Word> wordList(OPTION_COUNT);

    for (int i = 0; i < OPTION_COUNT; i++) {
        Word word = hashTable.randomWord(randomIndex(size));

        if (word.first == "" ||
            checkWordExistInWordList(word.first, wordList)) {
            continue;
        }

        wordList[i] = word;
    }

    int correctOption = randomIndex(OPTION_COUNT);
    return RandomList(wordList, correctOption);
}

void Dictionary::editDefinitionOfWord(
    const QString &key, const std::vector<QString> &val
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
