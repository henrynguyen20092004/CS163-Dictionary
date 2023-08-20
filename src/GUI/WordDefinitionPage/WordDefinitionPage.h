#ifndef WORD_DEFINITION_PAGE_H
#define WORD_DEFINITION_PAGE_H

#include <vector>

#include "../Components/Modal/ConfirmModal/ConfirmModal.h"
#include "../Page/Page.h"
#include "Components/EditWord/EditWord.h"

class WordDefinitionPage : public Page {
    Q_OBJECT

   private:
    TextLabel *keyWordLabel;
    Button *deleteButton, *favoriteButton;
    EditWord *editWord;
    TextLabel *wordLabel, *addDefinitionLabel;
    Button *addButton;
    ConfirmModal *confirmModal;
    std::vector<Definition *> definitions;

   public:
    WordDefinitionPage();
    ~WordDefinitionPage();

   public slots:
    void setWord(const QString &word);

   signals:
    void wordDeleted();
};

#endif
