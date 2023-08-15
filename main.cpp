#include <QApplication>

#include "src/GUI/Screen/Screen.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    QApplication app(argc, argv);
    Screen screen;
    return app.exec();
}
