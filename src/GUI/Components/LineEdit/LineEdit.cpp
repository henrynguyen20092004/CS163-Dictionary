#include "LineEdit.h"

LineEdit::LineEdit(QWidget* parent, const char* lineStyle) : QLineEdit(parent) {
    setText(content);
    setStyleSheet(lineStyle);
}

LineEdit::LineEdit(
    QWidget* parent, const char* lineStyle, const QRect& geometry
)
    : QLineEdit(parent) {
    setGeometry(geometry);
    setText(content);
    setStyleSheet(lineStyle);
}
