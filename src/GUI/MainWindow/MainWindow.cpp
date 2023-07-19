#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) {
    background = new Frame(this, 0, 0, 1280, 319, "background-color: #001C30;");
    headerBar = new HeaderBar(this);
    logo = new Image(this, 30, 88, 188, 150, "assets/UniLogo.png");
    searchBar = new SearchBar(this);
    languageButton = new LanguageButton(this);
    wordDefinitionButton = new WordDefinitionButton(this);
    menu = new Menu(this);
}

MainWindow::~MainWindow() {
    delete background;
    delete headerBar;
    delete logo;
    delete searchBar;
    delete languageButton;
    delete wordDefinitionButton;
    delete menu;
}
