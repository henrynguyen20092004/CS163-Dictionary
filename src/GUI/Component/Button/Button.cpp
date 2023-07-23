#include "Button.h"

Button::Button(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* buttonStyle
) {
    initButton(parent, posX, posY, width, height);
    button->setStyleSheet(buttonStyle);
}

Button::Button(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* buttonStyle, const char* content
) {
    initButton(parent, posX, posY, width, height);
    button->setStyleSheet(buttonStyle);
    button->setText(content);
}

Button::Button(
    QWidget* parent, const char* placeOnImageHolder, int posX, int posY,
    int width, int height
) {
    initButton(parent, posX, posY, width, height);
    button->setIcon(QIcon(placeOnImageHolder));
    button->setIconSize(QSize(width, height));
}

void Button::initButton(
    QWidget* parent, int posX, int posY, int width, int height
) {
    button = new QPushButton(parent);
    button->setGeometry(posX, posY, width, height);
}

Button::~Button() { delete button; }
