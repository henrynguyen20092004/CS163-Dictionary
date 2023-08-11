#include "Image.h"

Image::Image(QWidget* parent, const char* imageSrc, const QRect& geometry)
    : QLabel(parent) {
    setGeometry(geometry);
    setPixmap(QPixmap(imageSrc));
}
