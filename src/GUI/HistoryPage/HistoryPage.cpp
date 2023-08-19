#include "HistoryPage.h"

#include "../../GlobalVar/GlobalVar.h"

HistoryPage::HistoryPage() : Page("HISTORY") {}

void HistoryPage::clear() {
    for (HistoryWord* word : historyWords) {
        delete word;
    }

    historyWords.clear();
}

void HistoryPage::reload() {
    clear();

    for (const KeyWithDictName& word : *GlobalVar::data.history.getHistory()) {
        if (word.dictionaryName ==
            GlobalVar::currentDictionary->dictionaryName) {
            historyWords.emplace_back(
                new HistoryWord(content, word.key, historyWords.size())
            );
            CONNECT(historyWords.back(), CLICKED, this, [=]() {
                emit historyWordClicked(word.key);
            });
        }
    }

    content->resize(
        content->width(),
        DISTANCE * historyWords.size() + WORD_BUTTONS_PADDING_Y
    );
}

HistoryPage::~HistoryPage() { clear(); }
