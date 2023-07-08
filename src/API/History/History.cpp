#include "History.h"

#include <QFile>
#include <QTextStream>

History::History() {
    QFile file(historyPath.c_str());

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        throw std::runtime_error(historyPath + " can't be loaded");
    }

    QTextStream fin(&file);

    while (!fin.atEnd()) {
        QString key = fin.readLine();
        wordHistory.push_back(key);
    }
}

void History::saveData() {
    QFile file(historyPath.c_str());

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        throw std::runtime_error(historyPath + " can't be loaded");
    }

    QTextStream fout(&file);

    for (int i = 0; i < wordHistory.size(); ++i) {
        fout << wordHistory[i] << '\n';
    }
}

void History::add(const QString& key) {
    if (wordHistory.size() == maxSize) {
        for (int i = 0; i < wordHistory.size() - 1; ++i) {
            wordHistory[i] = wordHistory[i + 1];
        }

        wordHistory.pop_back();
    }

    wordHistory.push_back(key);
    saveData();
}

std::vector<QString> History::getHistory() { return wordHistory; }
