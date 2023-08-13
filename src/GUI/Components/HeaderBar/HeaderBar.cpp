#include "HeaderBar.h"

HeaderBar::HeaderBar(QWidget* parent, const QString& titleText)
    : QWidget(parent) {
    setGeometry(0, 0, 1280, HEADER_BAR_HEIGHT);
    setStyleSheet("background-color: #176B87;");

    title = new TextLabel(
        this, titleText, {}, "color: white; font-size: 24px; font-weight: 700;"
    );
    titleLayout = new QHBoxLayout(this);

    titleLayout->addWidget(title);
}

void HeaderBar::setTitle(const QString& titleText) {
    title->setText(titleText);
}

HeaderBar::~HeaderBar() {
    delete title;
    delete titleLayout;
}
