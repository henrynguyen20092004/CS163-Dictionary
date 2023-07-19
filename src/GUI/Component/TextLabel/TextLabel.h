#ifndef TEXT_LABEL_H
#define TEXT_LABEL_H

#include <QLabel>

class TextLabel {
   private:
    QLabel* textLabel;

   public:
    TextLabel(
        QWidget* parent, const char* textLabelContent,
        const char* textLabelStyle, int posX, int posY, int width, int height
    );
    ~TextLabel();
};

#endif
