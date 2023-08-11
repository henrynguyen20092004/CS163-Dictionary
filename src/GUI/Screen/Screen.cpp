#include "Screen.h"

#include "../Components/BackButton/BackButton.h"

Screen::Screen() {
    stackedWidget = new QStackedWidget;
    homePage = new HomePage;
    wordDefinitionPage = new WordDefinitionPage;

    BackButton::createInstance(homePage);
    stackedWidget->setWindowTitle("CSD");
    stackedWidget->setFixedWidth(1280);
    stackedWidget->setFixedHeight(720);
    stackedWidget->addWidget(homePage);
    stackedWidget->show();

    CONNECT(BackButton::getInstance(), CLICKED, [=]() {
        removeCurrentWidget();
    });
    CONNECT(homePage, &HomePage::searchResultClicked, [=](const QString& word) {
        wordDefinitionPage->setWord(word);
        addWidget(wordDefinitionPage);
    });
}

void Screen::addWidget(QWidget* widget) {
    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
    BackButton::getInstance()->setParent(widget);
    BackButton::getInstance()->show();
}

void Screen::removeCurrentWidget() {
    stackedWidget->removeWidget(stackedWidget->currentWidget());
    BackButton::getInstance()->setParent(stackedWidget->currentWidget());

    if (stackedWidget->currentWidget() == homePage) {
        BackButton::getInstance()->hide();
    }
}

Screen::~Screen() {
    BackButton::deleteInstance();
    delete homePage;
    delete wordDefinitionPage;
    delete stackedWidget;
}
