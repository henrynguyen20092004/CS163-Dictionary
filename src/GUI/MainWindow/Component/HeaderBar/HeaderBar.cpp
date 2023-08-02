#include "HeaderBar.h"

HeaderBar::HeaderBar(QWidget* parent) {
    setParent(parent);
    setGeometry(0, 0, 1280, HEADER_BAR_HEIGHT);
    setStyleSheet("background-color: #176B87;");

    textLabel = new TextLabel(
        this, "DICTIONARY", "color: white; font-size: 24px; font-weight: 700;",
        546, 12, 180, 24
    );
}

HeaderBar::~HeaderBar() { delete textLabel; }
