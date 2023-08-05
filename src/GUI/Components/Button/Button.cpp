#include "Button.h"

Button::Button(QWidget* parent, const char* buttonStyle, const char* content)
    : QPushButton(parent) {
    setStyleSheet(buttonStyle);
    setText(content);
}

Button::Button(
    QWidget* parent, const char* buttonStyle, const char* content,
    const QRect& geometry
)
    : QPushButton(parent) {
    setGeometry(geometry);
    setStyleSheet(buttonStyle);
    setText(content);
}

Button::Button(QWidget* parent, const char* imageSrc) : QPushButton(parent) {
    setIcon(QIcon(imageSrc));
}

Button::Button(
    QWidget* parent, const char* imageSrc, int width, int height, int posX,
    int posY
)
    : QPushButton(parent) {
    setGeometry(posX, posY, width, height);
    setIcon(QIcon(imageSrc));
    setIconSize(QSize(width, height));
}
