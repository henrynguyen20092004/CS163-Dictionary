#include "HeaderBar.h"

HeaderBar::HeaderBar(QWidget* parent) {
    headerBar = new Frame(parent, 0, 0, 1280, 50, "background-color: #176B87;");
    textLabel = new TextLabel(
        parent, "DICTIONARY",
        "color: white; font-size: 27px; font-weight: 700;", 546, 14, 187, 21
    );
    menuButton = new Button(parent, "assets/MenuButton.png", 0, 0, 60, 50);
}

HeaderBar::~HeaderBar() {
    delete headerBar;
    delete textLabel;
    delete menuButton;
}
