#include <QApplication>
#include <QMainWindow>

#include "src/GUI/MainWindow/MainWindow.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    MainWindow mainWindow;

    mainWindow.show();

    return app.exec();
g}
