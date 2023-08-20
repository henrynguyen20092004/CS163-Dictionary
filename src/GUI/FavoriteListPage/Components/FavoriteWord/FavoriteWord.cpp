#include "FavoriteWord.h"

#define REMOVE_BUTTON_SIZE 40

FavoriteWord::FavoriteWord(QWidget *parent, const QString &word, int index)
    : QWidget(parent) {
    favoriteWordButton = new Button(
        parent, "background-color: #D9D9D9; font-size: 18px; font-weight: 700;",
        word, {36, WORD_BUTTONS_PADDING_Y + DISTANCE * index, 648, 60}
    );
    removeButton = new Button(
        parent, "assets/XButton.png", REMOVE_BUTTON_SIZE,
        REMOVE_BUTTON_SIZE, 704, WORD_BUTTONS_PADDING_Y + 10 + DISTANCE * index
    );
}

Button* FavoriteWord::getFavoriteWordButton() { return favoriteWordButton; };

FavoriteWord::~FavoriteWord() {
    delete favoriteWordButton;
    delete removeButton;
}
