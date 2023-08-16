#ifndef LINE_EDIT_H
#define LINE_EDIT_H

#include <QLineEdit>

#define MAX_LENGTH 64

class LineEdit : public QLineEdit {
   private:
    const char content[MAX_LENGTH]{0};

   public:
    LineEdit(QWidget* parent, const char* lineStyle);
    LineEdit(QWidget* parent, const char* lineStyle, const QRect& geometry);
};

#endif
