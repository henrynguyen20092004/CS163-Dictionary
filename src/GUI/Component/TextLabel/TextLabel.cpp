#include "TextLabel.h"

TextLabel::TextLabel(
    QWidget* parent, const char* content, const char* textLabelStyle, int posX,
    int posY, int width, int height
) {
    setParent(parent);
    setText(content);
    setGeometry(posX, posY, width, height);
    setStyleSheet(textLabelStyle);
}
