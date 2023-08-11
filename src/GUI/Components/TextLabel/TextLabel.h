#ifndef TEXT_LABEL_H
#define TEXT_LABEL_H

#include <QLabel>
#include <string>

class TextLabel : public QLabel {
   public:
    TextLabel(
        QWidget* parent, const QString& content, const QRect& geometry = {},
        const char* textLabelStyle = nullptr
    );
};

#endif
