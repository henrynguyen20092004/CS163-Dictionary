#include "TextLabel.h"

TextLabel::TextLabel(
    QWidget* parent, const QString& content, const QRect& geometry,
    const char* textLabelStyle
)
    : QLabel(parent) {
    setText(content);
    setGeometry(geometry);
    setFixedWidth(geometry.width());
    setStyleSheet(textLabelStyle);
    setWordWrap(true);
    setAlignment(Qt::AlignCenter);
}
