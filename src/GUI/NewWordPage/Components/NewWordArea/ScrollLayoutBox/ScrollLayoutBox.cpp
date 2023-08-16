#include "ScrollLayoutBox.h"

ScrollLayoutBox::ScrollLayoutBox(QWidget* parent) : QScrollArea(parent) {
    container = new QWidget(this);
    layout = new QVBoxLayout(container);
    setWidget(container);
    setStyleSheet(scrollBarStyle);
    setWidgetResizable(true);
}

void ScrollLayoutBox::addWidget(QWidget* widget) { layout->addWidget(widget); }

QVBoxLayout* ScrollLayoutBox::getLayout() { return layout; }

QWidget* ScrollLayoutBox::getContainer() { return container; }

ScrollLayoutBox::~ScrollLayoutBox() {
    delete layout;
    delete container;
}
