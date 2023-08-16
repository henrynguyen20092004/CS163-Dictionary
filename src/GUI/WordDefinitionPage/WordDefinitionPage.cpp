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
    new Button(content, "assets/FavoriteButton.png", 36, 36, 704, 60);

    confirmModal =
        new ConfirmModal(this, "Are you sure you want to delete this word?");

    CONNECT(deleteButton, CLICKED, [=]() { confirmModal->toggle(); });

    CONNECT(confirmModal, &ConfirmModal::okButtonClicked, [=]() {
        confirmModal->grabMouse();
        GlobalVar::currentDictionary->removeWordFromDictionary(wordLabel->text()
        );
        confirmModal->releaseMouse();
        confirmModal->toggle();
        emit wordDeleted();
    });
}

void WordDefinitionPage::setWord(const QString& word) {
    headerBar->setTitle(word);
    keyWordLabel->setText(word);
    editWord->setWord(word);
}

void WordDefinitionPage::removeWord(const QString& word) {
    confirmModal->show();

    GlobalVar::currentDictionary->removeWordFromDictionary(word);
}

WordDefinitionPage::~WordDefinitionPage() {
    delete keyWordLabel;
    delete deleteButton;
    delete favoriteButton;
    delete editWord;
    delete confirmModal;
    for (Definition* definition : definitions) {
        delete definition;
    }
}
