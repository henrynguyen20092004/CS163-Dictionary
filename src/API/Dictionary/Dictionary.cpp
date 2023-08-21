#include "Dictionary.h"

#include <QFile>
#include <QRegularExpression>
#include <QTextStream>
#include <stdexcept>

#include "../../GlobalVar/GlobalVar.h"
#include "../HashTable/HashFunction/HashFunction.h"
#include "../RandomIndex/RandomIndex.h"
#include "../SubstringCheck/ProcessString/ProcessString.h"
#include "../SubstringCheck/SubstringCheck.h"
#include "LoadDictionary/LoadDictionary.h"

#define OPTION_COUNT 4

Dictionary::Dictionary(
    int size, const std::string &originalDictionaryPath,
    const std::string &newDictionaryPath, DictionaryName dictionaryName
)
    : size(size),
      dictionaryName(dictionaryName),
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

bool Dictionary::containWord(const QString &key) {
    return !hashTable.find(key, hashFunction(key, size)).empty();
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

std::vector<QString> Dictionary::getKeywordFromSubKeyword(
    const QString &subKeyword
) {
    QString newSubKeyword = subKeyword.toLower();
    CharacterTable characterTable(newSubKeyword);

    return hashTable.findKeywordIf([&](const QString &keyword,
                                       bool &isExactMatch) {
        QString newKeyword = keyword.toLower();

        if (newKeyword == newSubKeyword) {
            isExactMatch = true;
            return true;
        }

        return substringCheck(newKeyword, newSubKeyword, characterTable);
    });
}

std::vector<QString> Dictionary::getKeywordFromSubDefinition(
    const QString &subDefinition
) {
    QString newSubDefinition = processString(subDefinition);

    if (newSubDefinition.isEmpty()) {
        return {};
    }

    CharacterTable characterTable(newSubDefinition);

    return hashTable.findKeywordIf(
        [&](const QString &definition, bool &isExactMatch) {
            QString newDefinition = processString(definition);

            if (newDefinition == newSubDefinition) {
                isExactMatch = true;
                return true;
            }

            return substringCheck(
                newDefinition, newSubDefinition, characterTable
            );
        },
        false
    );
}

Word Dictionary::getRandomWord() {
    Word word;

    while (word.first.isEmpty()) {
        word = hashTable.randomWord(randomIndex(size));
    }

    return word;
}

RandomList Dictionary::getFourRandomWords() {
    std::vector<Word> wordList(OPTION_COUNT);

    for (int i = 0; i < OPTION_COUNT; i++) {
        Word word = getRandomWord();

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
    GlobalVar::data.favoriteList.removeWord({key, dictionaryName});
    GlobalVar::data.history.removeNonExistentWord(this);
    saveData(REMOVE, index, key);
}

void Dictionary::resetDictionary() {
    hashTable.clear();
    resetNewDictionaryFile();
    loadOriginalDictionary(originalDictionaryPath, hashTable);
    GlobalVar::data.favoriteList.removeNonExistentWord(this);
    GlobalVar::data.history.removeNonExistentWord(this);
}
