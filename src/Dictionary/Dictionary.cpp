#include "Dictionary.h"

Dictionary::Dictionary(
    int size, const std::string& originalDictionaryPath,
    const std::string& newDictionaryPath
)
    : originalDictionaryPath(originalDictionaryPath),
      newDictionaryPath(newDictionaryPath) {
    dictionary.table.resize(size, nullptr);
    loadNewDictionary(newDictionaryPath, dictionary);
}

Dictionary::~Dictionary() {}

void Dictionary::loadOriginalDictionary(
    const std::string& originalDictionaryPath, HashTable& dictionary
) {
    QFile file(originalDictionaryPath.c_str());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error(originalDictionaryPath + " can't be loaded");
    }

    QTextStream fin(&file);
    QString line;

    while (!fin.atEnd()) {
        QString key = fin.readLine().toLower();
        std::vector<QString> val;
        fin.readLineInto(&line);

        while (!line.isEmpty()) {
            val.push_back(line);
            fin.readLineInto(&line);
        }

        dictionary[key] = val;
    }
}

void Dictionary::loadNewDictionary(
    const std::string& newDictionaryPath, HashTable& dictionary
) {
    QFile file(newDictionaryPath.c_str());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error(newDictionaryPath + " can't be loaded");
    }

    QTextStream fin(&file);
    QString line;

    while (!fin.atEnd()) {
        fin.readLineInto(&line);
        QString key = fin.readLine().toLower();

        if (line == 'r') {
            dictionary.remove(key);
        } else {
            std::vector<QString> val;
            fin.readLineInto(&line);

            while (!line.isEmpty()) {
                val.push_back(line);
                fin.readLineInto(&line);
            }

            dictionary[key] = val;
        }
    }
}

HashTable::Node* Dictionary::search(QString& key, bool addFavorite) {
    HashTable::Node* isFind = dictionary.find(key);

    if (isFind) {
        if (addFavorite) {
            // Favorite
        }
        // History
    }

    return isFind;
}
