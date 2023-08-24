#include "Screen.h"

#include "../Components/BackButton/BackButton.h"
#include "../Components/Modal/ConfirmModal/ConfirmModal.h"
#include "../Components/Modal/SuccessModal/SuccessModal.h"

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
    ConfirmModal::createInstance(homePage);
    SuccessModal::createInstance(homePage);

    stackedWidget->setWindowTitle("CSD");
    stackedWidget->setFixedSize(1280, 720);
    stackedWidget->addWidget(homePage);
    stackedWidget->show();

    CONNECT(BackButton::getInstance(), CLICKED, [=]() {
        removeCurrentWidget();
    });
    CONNECT(wordDefinitionPage, &WordDefinitionPage::wordRemoved, [=]() {
        removeCurrentWidget();
        SuccessModal::setInstanceSuccessText("Word successfully removed!");
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
        wordQuizPage->getNewQuiz();
        addWidget(wordQuizPage);
    });
    CONNECT(homePage, &HomePage::definitionQuizButtonClicked, [=]() {
        definitionQuizPage->getNewQuiz();
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
    ConfirmModal::getInstance()->setParent(widget);
    SuccessModal::getInstance()->setParent(widget);
    BackButton::getInstance()->show();
}

void Screen::removeCurrentWidget() {
    QWidget* currentWidget =
        stackedWidget->widget(stackedWidget->currentIndex() - 1);
    BackButton::getInstance()->setParent(currentWidget);
    ConfirmModal::getInstance()->setParent(currentWidget);
    SuccessModal::getInstance()->setParent(currentWidget);

    if (currentWidget == homePage) {
        BackButton::getInstance()->hide();
    } else if (currentWidget == favoriteListPage) {
        favoriteListPage->reload();
    } else if (currentWidget == historyPage) {
        historyPage->reload();
    }

    stackedWidget->removeWidget(stackedWidget->currentWidget());
}

Screen::~Screen() {
    BackButton::deleteInstance();
    ConfirmModal::deleteInstance();
    SuccessModal::deleteInstance();

    delete homePage;
    delete wordDefinitionPage;
    delete favoriteListPage;
    delete wordQuizPage;
    delete definitionQuizPage;
    delete newWordPage;
    delete stackedWidget;
}
