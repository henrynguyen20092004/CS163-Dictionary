#include "ScrollArea.h"

ScrollArea::ScrollArea(
    QWidget* parent, QWidget* child, int width, int height, int posX, int posY
)
    : QScrollArea(parent) {
    setWidget(child);
    setGeometry(posX, posY, width, height);
    setStyleSheet("background: transparent");
    setFrameShape(QFrame::NoFrame);
}
