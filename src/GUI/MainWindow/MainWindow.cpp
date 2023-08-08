#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    setStyleSheet(mainStyle);

    background =
        new Frame(this, "background-color: #001C30;", {0, 0, 1280, 288});
    headerBar = new HeaderBar(this, "DICTIONARY");
    logo = new Image(this, "assets/UniLogo.png", {30, 88, 188, 150});
    searchBar = new SearchBar(this);
    switchDictionaryButton = new SwitchDictionaryButton(this);
    wordDefinitionButton = new WordDefinitionButton(this);
    menu = new Menu(this);
}

MainWindow::~MainWindow() {
    delete background;
    delete headerBar;
    delete logo;
    delete searchBar;
    delete switchDictionaryButton;
    delete wordDefinitionButton;
    delete menu;
}
