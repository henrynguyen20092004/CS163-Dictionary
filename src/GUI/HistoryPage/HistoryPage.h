#ifndef HISTORY_PAGE_H
#define HISTORY_PAGE_H

#include <vector>

#include "../../API/Dictionary/Dictionary.h"
#include "../Page/Page.h"
#include "Components/HistoryWord/HistoryWord.h"

class HistoryPage : public Page {
    Q_OBJECT

   private:
    std::vector<HistoryWord*> historyWords;

    void clear();

   public:
    HistoryPage();
    ~HistoryPage();
    void reload();

   signals:
    void historyWordClicked(const QString& word);
};

#endif
