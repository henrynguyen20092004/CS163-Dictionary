#include "ScrollArea.h"

ScrollArea::ScrollArea(QWidget* parent, QWidget* child, int width, int height)
    : QScrollArea(parent) {
    setWidget(child);
    setGeometry(0, 0, width, height);
    setStyleSheet("background: transparent");
    setFrameShape(QFrame::NoFrame);
}
