#ifndef IMAGE_H
#define IMAGE_H

#include <QLabel>

class Image : public QLabel {
   public:
    Image(QWidget* parent, const char* imageSrc, const QRect& geometry);
};

#endif
