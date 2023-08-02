#include "Screen.h"

Screen::Screen() {
    stackedWidget = new QStackedWidget;
    mainWindow = new MainWindow;
}

void Screen::setUpUI() {
    stackedWidget->setWindowTitle("CSD");
    stackedWidget->setFixedWidth(1280);
    stackedWidget->setFixedHeight(720);
    stackedWidget->addWidget(mainWindow);
    stackedWidget->show();
}

Screen::~Screen() {
    delete mainWindow;
    delete stackedWidget;
}
