#include "FavoriteWord.h"

#define REMOVE_BUTTON_SIZE 40

FavoriteWord::FavoriteWord(QWidget* parent, const QString& word, int index)
    : QWidget(parent) {
    setGeometry(36, WORD_BUTTONS_PADDING_Y + DISTANCE * index, 708, 60);

    favoriteWordButton = new Button(
        this, "background-color: #D9D9D9; font-size: 18px; font-weight: 700;",
        word, {0, 0, 648, 60}
    );
    removeButton = new Button(
        this, "assets/XButton.png", REMOVE_BUTTON_SIZE, REMOVE_BUTTON_SIZE, 668,
        10
    );
}

Button* FavoriteWord::getFavoriteWordButton() { return favoriteWordButton; }

Button* FavoriteWord::getRemoveButton() { return removeButton; }

FavoriteWord::~FavoriteWord() {
    delete favoriteWordButton;
    delete removeButton;
}
