#include "Screen.h"

Screen::Screen() {
    stackedWidget = new QStackedWidget;
    mainWindow = new MainWindow;
    widgetDefinition = new WidgetDefinition;
    QObject::connect(mainWindow->lookupButton, &QPushButton::clicked, [&]() {
        stackedWidget->setCurrentIndex(1);
    });
}

void Screen::setUpUi() {
    stackedWidget->setWindowTitle("CSD");
    stackedWidget->setMinimumWidth(1280);
    stackedWidget->setMinimumHeight(720);
    stackedWidget->addWidget(mainWindow);
    stackedWidget->addWidget(widgetDefinition);
    return;
}
