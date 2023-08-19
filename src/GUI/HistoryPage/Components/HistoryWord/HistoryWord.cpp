#include "HistoryWord.h"

#define WORD_BUTTON_X 36

HistoryWord::HistoryWord(QWidget *parent, const QString &word, int index)
    : Button(
          parent,
          "background-color: #D9D9D9; font-size: 18px; font-weight: 700;", word,
          {WORD_BUTTON_X, WORD_BUTTONS_PADDING_Y + DISTANCE * index,
           parent->width() - WORD_BUTTON_X * 2, 60}
      ) {}
