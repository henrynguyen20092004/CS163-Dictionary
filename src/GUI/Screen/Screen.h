#ifndef SCREEN_H
#define SCREEN_H

#include <QStackedWidget>

#include "../HomePage/HomePage.h"
#include "../WordDefinitionPage/WordDefinitionPage.h"
#include "../WordQuizPage/WordQuizPage.h"

class Screen {
   private:
    HomePage* homePage;
    WordDefinitionPage* wordDefinitionPage;
    WordQuizPage* wordQuizPage;
    QStackedWidget* stackedWidget;

   public:
    Screen();
    ~Screen();
    void addWidget(QWidget* widget);
    void removeCurrentWidget();
};

#endif
