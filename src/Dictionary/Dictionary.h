#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QFile>
#include <QString>
#include <QTextStream>

#include "src/HashTable/HashTable.h"

class Dictionary {
   private:
    std::string originalDictionaryPath;
    std::string newDictionaryPath;
    HashTable dictionary;

    void loadNewDictionary(
        const std::string& newDictionaryPath, HashTable& dictionary
    );

    void loadOriginalDictionary(
        const std::string& originalDictionaryPath, HashTable& dictionary
    );

    bool saveDictionary();

   public:
    Dictionary(
        int size, const std::string& originalDictionaryPath,
        const std::string& newDictionaryPath
    );

    ~Dictionary();

    HashTable::Node* search(QString& key, bool addFavorite);
};

#endif
