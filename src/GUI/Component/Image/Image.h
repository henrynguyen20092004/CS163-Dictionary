#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

class Image {
   private:
    QLabel* image;

   public:
    Image(
        QWidget* parent, int posX, int posY, int width, int height,
        const char* placeOnImageHolder
    );
    ~Image();
};

#endif
