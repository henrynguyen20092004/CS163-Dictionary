#include "TextEdit.h"

TextEdit::TextEdit(QWidget* parent, const char* style, const QString& content)
    : QTextEdit(parent) {
    setStyleSheet(style);
    setText(content);
}
