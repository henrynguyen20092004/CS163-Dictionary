#ifndef SCREEN_H
#define SCREEN_H

#include <QStackedWidget>

#include "../FavoriteListPage/FavoriteListPage.h"
#include "../DefinitionQuizPage/DefinitionQuizPage.h"
#include "../HistoryPage/HistoryPage.h"
#include "../HomePage/HomePage.h"
#include "../NewWordPage/NewWordPage.h"
#include "../WordDefinitionPage/WordDefinitionPage.h"
#include "../WordQuizPage/WordQuizPage.h"

class Screen {
   private:
    HomePage* homePage;
    WordDefinitionPage* wordDefinitionPage;
    FavoriteListPage* favoriteListPage;
    HistoryPage* historyPage;
    WordQuizPage* wordQuizPage;
    DefinitionQuizPage* definitionQuizPage;
    NewWordPage* newWordPage;
    QStackedWidget* stackedWidget;

   public:
    Screen();
    ~Screen();
    void addWidget(QWidget* widget);
    void removeCurrentWidget();
};

#endif
