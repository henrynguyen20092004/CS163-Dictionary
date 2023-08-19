#ifndef HISTORY_WORD_H
#define HISTORY_WORD_H

#include "../../../Components/Button/Button.h"

#define WORD_BUTTONS_PADDING_Y 30
#define DISTANCE 80

class HistoryWord : public Button {
   public:
    HistoryWord(QWidget *parent, const QString &word, int index);
};

#endif
