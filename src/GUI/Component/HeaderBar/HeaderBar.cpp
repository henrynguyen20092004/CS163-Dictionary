#include "HeaderBar.h"

HeaderBar::HeaderBar(QWidget* parent, const char* titleText) : QWidget(parent) {
    setGeometry(0, 0, 1280, HEADER_BAR_HEIGHT);
    setStyleSheet("background-color: #176B87;");

    title = new TextLabel(
        this, titleText, {}, "color: white; font-size: 24px; font-weight: 700;"
    );
    titleLayout = new QHBoxLayout(this);

    titleLayout->addWidget(title);
}

HeaderBar::~HeaderBar() {
    delete title;
    delete titleLayout;
}
