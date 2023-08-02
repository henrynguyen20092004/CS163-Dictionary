#include "Image.h"

Image::Image(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* imageSrc
) {
    setParent(parent);
    setGeometry(posX, posY, width, height);
    setPixmap(QPixmap(imageSrc));
}
