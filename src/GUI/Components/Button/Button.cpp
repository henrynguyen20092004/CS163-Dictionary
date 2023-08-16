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

Button::Button(QWidget* parent, const char* imageSrc, QSize imageSize)
    : Button(parent, imageSrc) {
    setIconSize(imageSize);
    setStyleSheet("background-color: transparent;");
}

Button::Button(
    QWidget* parent, const char* imageSrc, int width, int height, int posX,
    int posY
)
    : Button(parent, imageSrc, {width, height}) {
    setGeometry(posX, posY, width, height);
}
