#include "LoadDictionary.h"

void loadOriginalDictionary(
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

void loadNewDictionary(
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

HashTable loadDictionary(
    int size, const std::string& originalDictionaryPath,
    const std::string& newDictionaryPath
) {
    HashTable dictionary(size);
    loadOriginalDictionary(originalDictionaryPath, dictionary);
    loadNewDictionary(newDictionaryPath, dictionary);
    return dictionary;
}
