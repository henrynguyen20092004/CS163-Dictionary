#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button {
   private:
    QPushButton* button;

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
        QWidget* parent, const char* placeOnImageHolder, int posX, int posY,
        int width, int height
    );
    void initButton(QWidget* parent, int posX, int posY, int width, int height);
    ~Button();
};

#endif
