#ifndef DICTIONARY_H
#define DICTIONARY_H

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

struct RandomList {
    std::vector<Word> word;
    int correctOption;

    RandomList(const std::vector<Word>& word, int correctOption)
        : word(word), correctOption(correctOption) {}
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
    bool checkWordExistInWordList(
        const QString& word, const std::vector<Word>& wordList
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
    std::vector<QString> getKeywordFromSubKeyword(
        const QString& subKeyword
    );
    std::vector<QString> getKeywordFromSubDefinition(
        const QString& subDefinition
    );
    RandomList getFourRandomWords();
    void editDefinitionOfWord(
        const QString& key, const std::vector<QString>& val
    );
    void removeWordFromDictionary(const QString& key);
    void resetDictionary();
};

#endif
