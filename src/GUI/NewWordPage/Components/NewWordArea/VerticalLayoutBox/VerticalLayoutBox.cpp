#include "VerticalLayoutBox.h"

VerticalLayoutBox::VerticalLayoutBox(
    QWidget* parent, const char* widgetStyle, QRect geometry
)
    : QWidget(parent) {
    layout = new QVBoxLayout(this);
    setStyleSheet(widgetStyle);
    setGeometry(geometry);
}

void VerticalLayoutBox::addWidget(QWidget* widget) {
    layout->addWidget(widget);
}

VerticalLayoutBox::~VerticalLayoutBox() { delete layout; }
