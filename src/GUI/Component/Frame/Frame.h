#ifndef FRAME_H
#define FRAME_H

#include <QFrame>

class Frame : public QFrame {
   public:
    Frame(QWidget* parent, const char* frameStyle, const QRect& geometry);
};

#endif
