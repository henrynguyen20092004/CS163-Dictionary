#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

#define CONNECT QObject::connect
#define CLICKED &QPushButton::clicked

class Button : public QPushButton {
   public:
    Button(
        QWidget* parent, int posX, int posY, int width, int height,
        const char* buttonStyle
    );
    Button(
        QWidget* parent, int posX, int posY, int width, int height,
        const char* buttonStyle, const char* content
    );
    Button(
        QWidget* parent, const char* imageSrc, int posX, int posY, int width,
        int height
    );
    void initButton(QWidget* parent, int posX, int posY, int width, int height);
};

#endif
