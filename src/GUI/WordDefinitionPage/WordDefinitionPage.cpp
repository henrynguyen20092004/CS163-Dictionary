#include "WordDefinitionPage.h"

#include "../../GlobalVar/GlobalVar.h"
#include "../Components/Modal/ConfirmModal/ConfirmModal.h"

WordDefinitionPage::WordDefinitionPage() : Page("") {
    keyWordLabel = new TextLabel(
        content, "", {36, 48, 720, 60},
        "background-color: #D9D9D9; font-size: 24px; font-weight: 700;"
    );
    removeButton =
        new Button(content, "assets/RemoveButton.png", 36, 36, 36, 8);
    favoriteButton = new FavoriteButton(
        content, "assets/FavoriteButtonOff.png", 36, 36, 704, 60
    );
    editWord = new EditWord(content, this);

    CONNECT(removeButton, CLICKED, [=]() {
        ConfirmModal::setInstanceConfirmText(
            "Are you sure you want to delete this word?"
        );
    });
}

void WordDefinitionPage::setWord(const QString& word) {
    headerBar->setTitle(word);
    keyWordLabel->setText(word);
    editWord->setWord(word);
    favoriteButton->setWord(word);
    ConfirmModal::disconnectInstanceOkButton();

    CONNECT(ConfirmModal::getInstanceOkButton(), CLICKED, [=]() {
        GlobalVar::currentDictionary->removeWordFromDictionary(word);
        ConfirmModal::hideInstance();
        emit wordRemoved();
    });
}

WordDefinitionPage::~WordDefinitionPage() {
    delete keyWordLabel;
    delete removeButton;
    delete favoriteButton;
    delete editWord;

    for (Definition* definition : definitions) {
        delete definition;
    }
}
