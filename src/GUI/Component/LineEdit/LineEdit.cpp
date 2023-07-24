#include "LineEdit.h"

LineEdit::LineEdit(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* lineStyle
) {
    setParent(parent);
    setText(content);
    setGeometry(posX, posY, width, height);
    setStyleSheet(lineStyle);
}
