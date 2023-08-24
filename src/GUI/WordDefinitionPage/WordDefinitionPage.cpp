#include "WordDefinitionPage.h"

#include "../../GlobalVar/GlobalVar.h"

WordDefinitionPage::WordDefinitionPage() : Page("") {
    keyWordLabel = new TextLabel(
        content, "", {36, 48, 720, 60},
        "background-color: #FFFFFF; font-size: 24px; font-weight: 700;"
    );
    removeButton =
        new Button(content, "assets/RemoveButton.png", 36, 36, 36, 8);
    favoriteButton =
        new FavoriteButton(content, "assets/FavoriteButtonOff.png", 36, 36, 704, 60);
    editWord = new EditWord(content, this);

    confirmModal =
        new ConfirmModal(this, "Are you sure you want to delete this word?");

    CONNECT(removeButton, CLICKED, [=]() { confirmModal->show(); });
}

void WordDefinitionPage::setWord(const QString& word) {
    headerBar->setTitle(word);
    keyWordLabel->setText(word);
    editWord->setWord(word);
    favoriteButton->setWord(word);
    confirmModal->hide();
    confirmModal->disconnect();

    CONNECT(confirmModal, &ConfirmModal::okButtonClicked, [=]() {
        confirmModal->grabMouse();
        GlobalVar::currentDictionary->removeWordFromDictionary(word);
        confirmModal->releaseMouse();
        confirmModal->hide();
        emit wordRemoved();
    });
}

WordDefinitionPage::~WordDefinitionPage() {
    delete keyWordLabel;
    delete removeButton;
    delete favoriteButton;
    delete editWord;
    delete confirmModal;

    for (Definition* definition : definitions) {
        delete definition;
    }
}
