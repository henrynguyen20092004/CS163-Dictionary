#include "LineEdit.h"

LineEdit::LineEdit(QWidget* parent, const char* lineStyle) : QLineEdit(parent) {
    setText(content);
    setStyleSheet(lineStyle);
    setMaxLength(MAX_LENGTH);
}

LineEdit::LineEdit(
    QWidget* parent, const char* lineStyle, const QRect& geometry
)
    : LineEdit(parent, lineStyle) {
    setGeometry(geometry);
}
