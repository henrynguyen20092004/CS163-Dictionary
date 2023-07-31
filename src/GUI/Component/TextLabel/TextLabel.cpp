#include "TextLabel.h"

TextLabel::TextLabel(
    QWidget* parent, const QString& content, const char* textLabelStyle,
    int posX, int posY, int width, int height
) {
    setParent(parent);
    setGeometry(posX, posY, width, height);
    setStyleSheet(textLabelStyle);
    setText(content);
    setWordWrap(true);
}

TextLabel::TextLabel(
    QWidget* parent, const std::string& content, const char* textLabelStyle,
    int posX, int posY, int width, int height
)
    : TextLabel(
          parent, QString::fromStdString(content), textLabelStyle, posX, posY,
          width, height
      ) {}

TextLabel::TextLabel(
    QWidget* parent, const char* content, const char* textLabelStyle, int posX,
    int posY, int width, int height
)
    : TextLabel(
          parent, QString(content), textLabelStyle, posX, posY, width, height
      ) {}
