#include "LoadData.h"

#include <QtCore>

void loadOriginalDict(const std::string& originalDictPath, HashTable& dict) {
    QFile file(originalDictPath.c_str());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error(originalDictPath + " can't be loaded");
    }

    QTextStream fin(&file);
    QString line;

    while (!fin.atEnd()) {
        std::wstring key = fin.readLine().toStdWString();
        std::vector<std::wstring> val;
        fin.readLineInto(&line);

        while (!line.isEmpty()) {
            val.push_back(line.toStdWString());
            fin.readLineInto(&line);
        }

        dict[key] = val;
    }
}

void loadNewDict(const std::string& newDictPath, HashTable& dict) {
    QFile file(newDictPath.c_str());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error(newDictPath + " can't be loaded");
    }

    QTextStream fin(&file);
    QString line;

    while (!fin.atEnd()) {
        fin.readLineInto(&line);
        std::wstring key = fin.readLine().toStdWString();

        if (line == 'r') {
            dict.remove(key);
        } else {
            std::vector<std::wstring> val;
            fin.readLineInto(&line);

            while (!line.isEmpty()) {
                val.push_back(line.toStdWString());
                fin.readLineInto(&line);
            }

            dict[key] = val;
        }
    }
}

HashTable loadData(
    int size,
    const std::string& originalDictPath, const std::string& newDictPath
) {
    HashTable dict(size);
    loadOriginalDict(originalDictPath, dict);
    loadNewDict(newDictPath, dict);
    return dict;
}
