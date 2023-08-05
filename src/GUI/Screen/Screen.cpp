#include "Screen.h"

#include "../Components/BackButton/BackButton.h"

Screen::Screen() {
    stackedWidget = new QStackedWidget;
    homePage = new HomePage;
    wordDefinitionPage = new WordDefinitionPage;
    wordQuizPage = new WordQuizPage;
    newWordPage = new NewWordPage;

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
    CONNECT(homePage, &HomePage::wordQuizButtonClicked, [=]() {
        addWidget(wordQuizPage);
    });
    CONNECT(homePage, &HomePage::newWordButtonClicked, [=]() {
        addWidget(newWordPage);
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
    delete wordQuizPage;
    delete newWordPage;
    delete stackedWidget;
}
