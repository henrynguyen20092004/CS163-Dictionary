#include "Frame.h"

Frame::Frame(QWidget* parent, const char* frameStyle, const QRect& geometry)
    : QFrame(parent) {
    setGeometry(geometry);
    setStyleSheet(frameStyle);
}
