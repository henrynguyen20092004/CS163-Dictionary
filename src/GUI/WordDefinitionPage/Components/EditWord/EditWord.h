#ifndef EDIT_WORD_H
#define EDIT_WORD_H

#include "../../../Components/Modal/SuccessModal/SuccessModal.h"
#include "Components/DefinitionArea/DefinitionArea.h"

class EditWord {
   private:
    TextLabel *addDefinitionLabel, *errorLabel;
    Button *addButton, *saveButton, *discardButton;
    SuccessModal *successModal;
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