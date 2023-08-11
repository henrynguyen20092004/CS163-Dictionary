#ifndef WORD_DEFINITION_BUTTON_H
#define WORD_DEFINITION_BUTTON_H

#include "../../../Components/Button/Button.h"

enum Mode { WORD_DEFINITION, DEFINITION_WORD };

class WordDefinitionButton {
   private:
    Button *wordDefinitionButton, *definitionWordButton;
    const char *buttonStyle =
        "QPushButton {background-color: #119ECD; border-radius: 10px; "
        "font-size: 16px; font-weight: 500;} QPushButton::hover "
        "{background-color: #09ED12;}";
    const char *activeButtonStyle =
        "QPushButton {background-color: #09ED12; border-radius: 10px; "
        "font-size: 16px; font-weight: 500;}";

   public:
    static Mode searchMode;

    WordDefinitionButton(QWidget *parent);
    ~WordDefinitionButton();
};

#endif
