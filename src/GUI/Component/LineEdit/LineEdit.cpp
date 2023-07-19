#include "LineEdit.h"

LineEdit::LineEdit(
    QWidget* parent, int posX, int posY, int width, int height,
    const char* lineStyle
) {
    lineEdit = new QLineEdit(parent);
    lineEdit->setText(content);
    lineEdit->setGeometry(posX, posY, width, height);
    lineEdit->setStyleSheet(lineStyle);
}

LineEdit::~LineEdit() { delete lineEdit; }
