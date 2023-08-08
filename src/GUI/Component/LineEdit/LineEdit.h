#ifndef LINE_EDIT_H
#define LINE_EDIT_h

#include <QLineEdit>

class LineEdit : public QLineEdit {
   private:
    const char content[256]{0};

   public:
    LineEdit(QWidget* parent, const char* lineStyle, const QRect& geometry);
};

#endif
