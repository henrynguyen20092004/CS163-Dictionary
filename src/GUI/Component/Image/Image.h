#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

class Image : public QLabel {
   public:
    Image(
        QWidget* parent, int posX, int posY, int width, int height,
        const char* placeOnImageHolder
    );
};

#endif
