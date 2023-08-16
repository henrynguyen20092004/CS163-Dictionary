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
        DictionaryName dictionaryName = (DictionaryName)fin.readLine().toInt();
        wordHistory.push_back({key, dictionaryName});
    }
}

void History::saveList() {
    QFile file(historyPath.c_str());

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        throw std::runtime_error(historyPath + " can't be loaded");
    }

    QTextStream fout(&file);

    for (const KeyWithDictName& word : wordHistory) {
        fout << word.key << '\n' << word.dictionaryName << '\n';
    }
}

void History::add(const KeyWithDictName& data) {
    if (wordHistory.size() == maxSize) {
        wordHistory.pop_back();
    }

    wordHistory.insert(wordHistory.begin(), data);
    saveList();
}

std::vector<KeyWithDictName>* History::getHistory() { return &wordHistory; }

void History::removeNonExistentWord(Dictionary* dictionary) {
    wordHistory.erase(
        std::remove_if(
            wordHistory.begin(), wordHistory.end(),
            [=](const KeyWithDictName& word) {
                if (word.dictionaryName == dictionary->dictionaryName) {
                    try {
                        dictionary->getDefinition(word.key);
                    } catch (...) {
                        return true;
                    }
                }

                return false;
            }
        ),
        wordHistory.end()
    );

    saveList();
}
