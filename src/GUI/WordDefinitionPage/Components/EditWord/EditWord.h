#ifndef EDIT_WORD_H
#define EDIT_WORD_H

#include "Components/DefinitionArea/DefinitionArea.h"

class EditWord {
   private:
    TextLabel *errorLabel;
    Button *addButton, *addDefinitionButton, *saveButton, *discardButton;
    DefinitionArea *definitionArea;
    const char *saveButtonStyle =
        "QPushButton {background-color: #119ECD; border-radius: "
        "10px; color: white; font-weight: 500;} QPushButton::hover "
        "{background-color: #09ED12;}";

    void checkDefinition();

   public:
    EditWord(QWidget *parent, QWidget *page);
    ~EditWord();
    void setWord(const QString &word);
};

#endif
