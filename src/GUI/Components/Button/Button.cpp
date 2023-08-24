#include "Button.h"

Button::Button(QWidget* parent, const char* buttonStyle, const QString& content)
    : QPushButton(parent) {
    setStyleSheet(buttonStyle);
    setText(content);
}

Button::Button(
    QWidget* parent, const char* buttonStyle, const QString& content,
    const QRect& geometry
)
    : Button(parent, buttonStyle, content) {
    setGeometry(geometry);
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
    : Button(parent, imageSrc, QSize(width, height)) {
    setGeometry(posX, posY, width, height);
}
