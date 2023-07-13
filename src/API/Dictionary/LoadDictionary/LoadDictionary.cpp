#include "LoadDictionary.h"

#include <QFile>
#include <QTextStream>

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
        int index = fin.readLine().toInt();
        fin.readLineInto(&line);

        while (!line.isEmpty()) {
            QString key = line;
            std::vector<QString> val;
            fin.readLineInto(&line);

            while (!line.isEmpty()) {
                val.push_back(line);
                fin.readLineInto(&line);
            }

            dictionary.insert(key, val, index);
            fin.readLineInto(&line);
        }
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
        int index = fin.readLine().toInt();
        QChar mode = fin.readLine()[0];
        QString key = fin.readLine();

        if (mode == 'r') {
            dictionary.remove(key, index);
        } else {
            std::vector<QString> val;
            fin.readLineInto(&line);

            while (!line.isEmpty()) {
                val.push_back(line);
                fin.readLineInto(&line);
            }

            if (mode == 'a') {
                dictionary.insert(key, val, index);
            } else {
                dictionary.update(key, val, index);
            }
        }
    }
}
