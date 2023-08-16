#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

#define CONNECT QObject::connect
#define CLICKED &QPushButton::clicked

class Button : public QPushButton {
   public:
    Button(QWidget* parent, const char* buttonStyle, const char* content);
    Button(
        QWidget* parent, const char* buttonStyle, const char* content,
        const QRect& geometry
    );
    Button(QWidget* parent, const char* imageSrc);
    Button(QWidget* parent, const char* imageSrc, QSize imageSize);
    Button(
        QWidget* parent, const char* imageSrc, int width, int height,
        int posX = 0, int posY = 0
    );
};

#endif
