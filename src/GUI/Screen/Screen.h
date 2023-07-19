#ifndef SCREEN_H
#define SCREEN_H

#include <QStackedWidget>

#include "../MainWindow/MainWindow.h"

class Screen {
   private:
    MainWindow* mainWindow;
    QStackedWidget* stackedWidget;

   public:
    Screen();
    ~Screen();
    void setUpUi();
};

#endif
