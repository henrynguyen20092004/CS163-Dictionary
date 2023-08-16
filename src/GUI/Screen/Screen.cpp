#include "Screen.h"

#include "../Components/BackButton/BackButton.h"

Screen::Screen() {
    stackedWidget = new QStackedWidget;
    homePage = new HomePage;
    wordDefinitionPage = new WordDefinitionPage;
    favoriteListPage = new FavoriteListPage;
    wordQuizPage = new WordQuizPage;
    definitionQuizPage = new DefinitionQuizPage;
    newWordPage = new NewWordPage;
    historyPage = new HistoryPage;

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
    CONNECT(homePage, &HomePage::favoriteListButtonClicked, [=]() {
        favoriteListPage->reload();
        addWidget(favoriteListPage);
    });
    CONNECT(homePage, &HomePage::historyButtonClicked, [=]() {
        historyPage->reload();
        addWidget(historyPage);
    });
    CONNECT(homePage, &HomePage::wordQuizButtonClicked, [=]() {
        addWidget(wordQuizPage);
    });
    CONNECT(homePage, &HomePage::definitionQuizButtonClicked, [=]() {
        addWidget(definitionQuizPage);
    });
    CONNECT(homePage, &HomePage::newWordButtonClicked, [=]() {
        addWidget(newWordPage);
    });
    CONNECT(
        favoriteListPage, &FavoriteListPage::favoriteWordClicked,
        [=](const QString& word) {
            wordDefinitionPage->setWord(word);
            addWidget(wordDefinitionPage);
        }
    );
    CONNECT(
        historyPage, &HistoryPage::historyWordClicked,
        [=](const QString& word) {
            wordDefinitionPage->setWord(word);
            addWidget(wordDefinitionPage);
        }
    );
}

void Screen::addWidget(QWidget* widget) {
    stackedWidget->addWidget(widget);
    stackedWidget->setCurrentWidget(widget);
    BackButton::getInstance()->setParent(widget);
    BackButton::getInstance()->show();
}

void Screen::removeCurrentWidget() {
    BackButton::getInstance()->setParent(
        stackedWidget->widget(stackedWidget->currentIndex() - 1)
    );
    stackedWidget->removeWidget(stackedWidget->currentWidget());

    if (stackedWidget->currentWidget() == homePage) {
        BackButton::getInstance()->hide();
    }
}

Screen::~Screen() {
    BackButton::deleteInstance();
    delete homePage;
    delete wordDefinitionPage;
    delete favoriteListPage;
    delete wordQuizPage;
    delete definitionQuizPage;
    delete newWordPage;
    delete stackedWidget;
}
