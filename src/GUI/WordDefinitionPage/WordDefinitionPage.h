#ifndef WORD_DEFINITION_PAGE_H
#define WORD_DEFINITION_PAGE_H

#include <vector>

#include "../Page/Page.h"
#include "Components/EditWord/EditWord.h"
#include "Components/FavoriteButton/FavoriteButton.h"

class WordDefinitionPage : public Page {
    Q_OBJECT

   private:
    TextLabel *keyWordLabel;
    Button *removeButton;
    FavoriteButton* favoriteButton;
    EditWord *editWord;
    std::vector<Definition *> definitions;

   public:
    WordDefinitionPage();
    ~WordDefinitionPage();

   public slots:
    void setWord(const QString &word);

   signals:
    void wordRemoved();
};

#endif
