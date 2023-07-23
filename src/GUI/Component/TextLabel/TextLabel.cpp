#include "TextLabel.h"

TextLabel::TextLabel(
    QWidget* parent, const char* textLabelContent, const char* textLabelStyle,
    int posX, int posY, int width, int height
) {
    textLabel = new QLabel(textLabelContent, parent);
    textLabel->setGeometry(posX, posY, width, height);
    textLabel->setStyleSheet(textLabelStyle);
}

TextLabel::~TextLabel() { delete textLabel; }
