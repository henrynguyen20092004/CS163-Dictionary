#include "History.h"

History::History(QString& historyPath) : historyPath(historyPath) {
    loadData();
}

History::~History() { saveData(); }

bool History::loadData() {
    QFile file;

    file.setFileName(historyPath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return false;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString key;

        if (in.readLineInto(&key)) {
            if (key.size() != 0) {
                wordSet.push_back(key);
            }
        }
    }

    file.close();
    return true;
}

bool History::saveData() {
    QFile file;

    file.setFileName(historyPath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        return false;
    }

    QTextStream out(&file);

    for (int i = 0; i < wordSet.size(); ++i) {
        out << wordSet[i];

        if (i != wordSet.size() - 1) {
            out << '\n';
        }
    }

    return true;
}

int History::find(QString& key) {
    for (int i = 0; i < wordSet.size(); ++i) {
        if (wordSet[i] == key) {
            return i;
        }
    }

    return -1;
}

bool History::add(QString& key) {
    int pos = find(key);

    if (pos != -1) {
        wordSet.erase(wordSet.begin() + pos);
    }

    if (wordSet.size() == maxSize) {
        wordSet.erase(wordSet.begin());
    }

    wordSet.push_back(key);

    return true;
}

std::vector<QString> History::getHistory() { return wordSet; }
