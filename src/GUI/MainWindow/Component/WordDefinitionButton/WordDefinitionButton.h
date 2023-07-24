#ifndef WORD_DEFINITION_BUTTON_H
#define WORD_DEFINITION_BUTTON_H

#include "../../../Component/Button/Button.h"

class WordDefinitionButton {
   private:
    Button *wordDefinitionButton, *definitionWordButton;
    const char *buttonStyle =
        "QPushButton {background-color: #119ECD; border-radius: 10px; color: "
        "black; font-size: 16px; font-weight: 500;} QPushButton::hover "
        "{background-color: #09ED12;}";

   public:
    WordDefinitionButton(QWidget *parent);
    ~WordDefinitionButton();
};

#endif
