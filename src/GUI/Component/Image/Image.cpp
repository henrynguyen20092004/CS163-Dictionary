#include "Image.h"

Image::Image(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* placeOnImageHolder
) {
    image = new QLabel(parent);
    image->setGeometry(posX, posY, width, height);
    image->setPixmap(QPixmap(placeOnImageHolder));
}

Image::~Image() { delete image; }
