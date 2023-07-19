#include "Frame.h"

Frame::Frame(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* frameStyle
) {
    frame = new QFrame(parent);
    frame->setGeometry(posX, posY, width, height);
    frame->setStyleSheet(frameStyle);
}

Frame::~Frame() { delete frame; }
