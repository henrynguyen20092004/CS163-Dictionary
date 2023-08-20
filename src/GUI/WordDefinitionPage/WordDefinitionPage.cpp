#include "WordDefinitionPage.h"

#include "../../GlobalVar/GlobalVar.h"

WordDefinitionPage::WordDefinitionPage() : Page("") {
    keyWordLabel = new TextLabel(
        content, "", {36, 48, 720, 60},
        "background-color: #FFFFFF; font-size: 24px; font-weight: 700;"
    );
    deleteButton =
        new Button(content, "assets/DeleteButton.png", 36, 36, 36, 8);
    favoriteButton =
        new Button(content, "assets/FavoriteButtonOff.png", 36, 36, 704, 60);
    editWord = new EditWord(content, this);
}

void WordDefinitionPage::setWord(const QString& word) {
    headerBar->setTitle(word);
    keyWordLabel->setText(word);
    editWord->setWord(word);
}

WordDefinitionPage::~WordDefinitionPage() {
    delete keyWordLabel;
    delete deleteButton;
    delete favoriteButton;
    delete editWord;
}
