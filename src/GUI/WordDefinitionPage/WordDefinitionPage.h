#ifndef WORD_DEFINITION_PAGE_H
#define WORD_DEFINITION_PAGE_H

#include <vector>

#include "../Components/Button/Button.h"
#include "../Components/Modal/SuccessModal/SuccessModal.h"
#include "../Components/TextLabel/TextLabel.h"
#include "../Page/Page.h"
#include "Components/DefinitionBox/DefinitionBox.h"

class WordDefinitionPage : public Page {
    Q_OBJECT

   private:
    TextLabel *wordLabel, *addDefinitionLabel, *errorText;
    Button *addButton, *deleteButton, *favoriteButton, *saveButton;
    DefinitionBox *definitionBox;
    SuccessModal *successModal;
    const char *saveButtonStyle =
        "QPushButton {background-color: #119ECD; border-radius: "
        "10px; color: white; font-size: 20px; font-weight: 500;} "
        "QPushButton::hover {background-color: #09ED12;}";


   public:
    WordDefinitionPage();
    ~WordDefinitionPage();

   private slots:
    void checkDefinition();

   public slots:
    void setWord(const QString &word);
};

#endif
