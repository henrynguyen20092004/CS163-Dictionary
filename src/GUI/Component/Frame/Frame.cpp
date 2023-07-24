#include "Frame.h"

Frame::Frame(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* frameStyle
) {
    setParent(parent);
    setGeometry(posX, posY, width, height);
    setStyleSheet(frameStyle);
}
