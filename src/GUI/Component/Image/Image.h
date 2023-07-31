#ifndef IMAGE_H
#define IMAGE_H

#include <QLabel>

class Image : public QLabel {
   public:
    Image(
        QWidget* parent, int posX, int posY, int width, int height,
        const char* imageSrc
    );
};

#endif
