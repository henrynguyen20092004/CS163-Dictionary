#include <QApplication>

#include "src/GUI/Screen/Screen.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    Screen screen;
    screen.setUpUI();
    return app.exec();
}
