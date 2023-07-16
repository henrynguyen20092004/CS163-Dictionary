#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>
#include <time.h>

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

enum SaveMode {
    ADD = 'a',
    UPDATE = 'u',
    REMOVE = 'r',
};

class Dictionary {
   private:
    HashTable hashTable;
    std::string originalDictionaryPath, newDictionaryPath;
    int size;

    void resetNewDictionaryFile();

    void saveData(
        SaveMode saveMode, int index, const QString& key,
        const std::vector<QString>& val = {}
    );

    bool checkChoose(
        const std::vector<std::pair<QString, std::vector<QString>>>& listOfWord,
        const QString& chooseDefinition
    );

    QString Dictionary::chooseDefinition(
        const std::vector<std::pair<QString, std::vector<QString>>>& listOfWord,
        int option
    );

    void Dictionary::getWord(
        std::vector<std::pair<QString, std::vector<QString>>>& listOfWord
    );

   public:
    Dictionary(
        int size, const std::string& originalDictionaryPath,
        const std::string& newDictionaryPath
    );
    void addWordToDictionary(
        const QString& key, const std::vector<QString>& val
    );
    std::vector<QString> getDefinition(const QString& key);
    std::vector<QString> getKeywordFromSubDefinition(
        const QString& subDefinition
    );
    void editDefinitionOfWord(const QString& key, std::vector<QString>& val);
    void removeWordFromDictionary(const QString& key);
    void resetDictionary();
    bool randomWordWithFourDefinitions();
};

#endif
