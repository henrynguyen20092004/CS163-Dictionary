#include "LineEdit.h"

LineEdit::LineEdit(
    QWidget* parent, const char* lineStyle, const QRect& geometry
)
    : QLineEdit(parent) {
    setText(content);
    setGeometry(geometry);
    setStyleSheet(lineStyle);
}
