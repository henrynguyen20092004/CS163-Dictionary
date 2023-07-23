#ifndef FRAME_H
#define FRAME_H

#include <QFrame>

class Frame {
   private:
    QFrame* frame;

   public:
    Frame(
        QWidget* parent, int posX, int posY, int width, int height,
        const char* frameStyle
    );
    ~Frame();
};

#endif
