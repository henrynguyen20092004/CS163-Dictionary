#include "TextEdit.h"

TextEdit::TextEdit(QWidget* parent, const char* style) : QTextEdit(parent) {
    setStyleSheet(style);
}
