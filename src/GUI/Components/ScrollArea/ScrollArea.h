#ifndef SCROLL_AREA_H
#define SCROLL_AREA_H

#include <QScrollArea>

class ScrollArea : public QScrollArea {
   public:
    ScrollArea(
        QWidget* parent, QWidget* child, int width, int height, int posX = 0,
        int posY = 0
    );
};

#endif
