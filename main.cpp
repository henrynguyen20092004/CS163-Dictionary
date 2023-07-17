#include <QApplication>
#include <QMainWindow>

#include "src/GUI/Screen/Screen.h"
#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    Screen screen;
    screen.setUpUi();
    screen.stackedWidget->show();
    return app.exec();
g}
