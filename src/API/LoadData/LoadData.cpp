#include "LoadData.h"

#include <QtCore>

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
        std::wstring key = fin.readLine().toLower().toStdWString();
        std::vector<std::wstring> val;
        fin.readLineInto(&line);

        while (!line.isEmpty()) {
            val.push_back(line.toStdWString());
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
        std::wstring key = fin.readLine().toLower().toStdWString();

        if (line == 'r') {
            dictionary.remove(key);
        } else {
            std::vector<std::wstring> val;
            fin.readLineInto(&line);

            while (!line.isEmpty()) {
                val.push_back(line.toStdWString());
                fin.readLineInto(&line);
            }

            dictionary[key] = val;
        }
    }
}

HashTable loadData(
    int size, const std::string& originalDictionaryPath,
    const std::string& newDictionaryPath
) {
    HashTable dictionary(size);
    loadOriginalDictionary(originalDictionaryPath, dictionary);
    loadNewDictionary(newDictionaryPath, dictionary);
    return dictionary;
}
