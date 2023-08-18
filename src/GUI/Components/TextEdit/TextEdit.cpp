#include "TextEdit.h"

TextEdit::TextEdit(QWidget* parent, const char* style) : QTextEdit(parent) {
    setStyleSheet(style);
}

TextEdit::TextEdit(
    QWidget* parent, const QString& content, const char* textEditStyle
)
    : QTextEdit(parent) {
    setText(content);
    setReadOnly(true);
    setStyleSheet(textEditStyle);
}