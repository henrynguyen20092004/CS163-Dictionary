#ifndef DICTIONARY_H
#define DICTIONARY_H

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

   public:
    Dictionary(
        int size, const std::string& originalDictionaryPath,
        const std::string& newDictionaryPath
    );
    std::vector<QString> getDefinition(const QString& key);
    void addWordToDictionary(const QString& key, std::vector<QString>& val);
    void editDefinitionsOfAWord(const QString& key, std::vector<QString>& val);
    void removeWordFromDictionary(const QString& key);
    void resetDictionary();
};

#endif
