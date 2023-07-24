#ifndef FRAME_H
#define FRAME_H

#include <QFrame>

class Frame : public QFrame {
   public:
    Frame(
        QWidget* parent, int posX, int posY, int width, int height,
        const char* frameStyle
    );
};

#endif
