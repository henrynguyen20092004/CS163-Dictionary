#include "Menu.h"

Menu::Menu(QWidget* parent) {
    menuBar = new Frame(parent, 0, 50, 248, 670, "background-color: #CBBDBD;");
    favoriteListButton =
        new Button(parent, 0, 64, 248, 66, buttonStyle, "Your favorite list");
    historyButton =
        new Button(parent, 0, 143, 248, 66, buttonStyle, "Searched history");
    definitionQuizButton =
        new Button(parent, 0, 222, 248, 66, buttonStyle, "Definition quiz");
    wordQuizButton =
        new Button(parent, 0, 301, 248, 66, buttonStyle, "Word quiz");
    addNewWordButton =
        new Button(parent, 0, 380, 248, 66, buttonStyle, "Add a new word");
    resetButton = new Button(
        parent, 0, 459, 248, 66, buttonStyle, "Set to original dictionary"
    );
}

Menu::~Menu() {
    delete menuBar;
    delete favoriteListButton;
    delete historyButton;
    delete definitionQuizButton;
    delete wordQuizButton;
    delete addNewWordButton;
    delete resetButton;
}
