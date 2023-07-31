#ifndef TEXT_LABEL_H
#define TEXT_LABEL_H

#include <QLabel>
#include <string>

class TextLabel : public QLabel {
   public:
    TextLabel(
        QWidget* parent, const QString& content, const char* textLabelStyle,
        int posX, int posY, int width, int height
    );
    TextLabel(
        QWidget* parent, const std::string& content, const char* textLabelStyle,
        int posX, int posY, int width, int height
    );
    TextLabel(
        QWidget* parent, const char* content, const char* textLabelStyle,
        int posX, int posY, int width, int height
    );
};

#endif
