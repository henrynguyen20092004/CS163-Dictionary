#ifndef TEXT_LABEL_H
#define TEXT_LABEL_H

#include <QLabel>

class TextLabel : public QLabel {
   public:
    TextLabel(
        QWidget* parent, const char* content, const char* textLabelStyle,
        int posX, int posY, int width, int height
    );
};

#endif
