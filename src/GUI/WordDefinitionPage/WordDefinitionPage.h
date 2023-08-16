#ifndef WORD_DEFINITION_PAGE_H
#define WORD_DEFINITION_PAGE_H

#include <vector>

#include "../Page/Page.h"
#include "Components/Definition/Definition.h"
#include "../../GlobalVar/GlobalVar.h"

class WordDefinitionPage : public Page {
   private:
    TextLabel *wordLabel, *addDefinitionLabel;
    Button *addButton, *deleteButton, *favoriteButton;
    std::vector<Definition *> definitions;

   public:
    WordDefinitionPage();
    ~WordDefinitionPage();

   public slots:
    void setWord(const QString &word, Dictionary *dictionary = GlobalVar::currentDictionary);
};

#endif
