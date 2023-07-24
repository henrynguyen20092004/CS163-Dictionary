#include "Button.h"

Button::Button(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* buttonStyle
) {
    initButton(parent, posX, posY, width, height);
    setStyleSheet(buttonStyle);
}

Button::Button(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* buttonStyle, const char* content
) {
    initButton(parent, posX, posY, width, height);
    setStyleSheet(buttonStyle);
    setText(content);
}

Button::Button(
    QWidget* parent, const char* placeOnImageHolder, int posX, int posY,
    int width, int height
) {
    initButton(parent, posX, posY, width, height);
    setIcon(QIcon(placeOnImageHolder));
    setIconSize(QSize(width, height));
}

void Button::initButton(
    QWidget* parent, int posX, int posY, int width, int height
) {
    setParent(parent);
    setGeometry(posX, posY, width, height);
}
