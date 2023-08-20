#ifndef WORD_DEFINITION_PAGE_H
#define WORD_DEFINITION_PAGE_H

#include "../Page/Page.h"
#include "Components/EditWord/EditWord.h"

class WordDefinitionPage : public Page {
    Q_OBJECT

   private:
    TextLabel *keyWordLabel;
    Button *deleteButton, *favoriteButton;
    EditWord* editWord;

   public:
    WordDefinitionPage();
    ~WordDefinitionPage();

   public slots:
    void setWord(const QString &word);
};

#endif
