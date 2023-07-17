#ifndef SCREEN_H
#define SCREEN_H

#include "../MainWindow/MainWindow.h"
#include "../WidgetDefinition/WidgetDefinition.h"

class Screen {
   private:
    MainWindow* mainWindow;
    WidgetDefinition* widgetDefinition;

   public:
    QStackedWidget* stackedWidget;

    Screen();
    void setUpUi();
};

#endif
