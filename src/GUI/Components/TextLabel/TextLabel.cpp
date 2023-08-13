#include "TextLabel.h"

TextLabel::TextLabel(
    QWidget* parent, const QString& content, const QRect& geometry,
    const char* textLabelStyle
)
    : QLabel(parent) {
    setText(content);
    setGeometry(geometry);
    setStyleSheet(textLabelStyle);
    setWordWrap(true);
    setAlignment(Qt::AlignCenter);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
}
