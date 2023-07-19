#ifndef LINE_EDIT_H
#define LINE_EDIT_h

#include <QLineEdit>

class LineEdit {
   private:
    QLineEdit* lineEdit;
    const char content[256] {0};

   public:
    LineEdit(
        QWidget* parent, int posX, int posY, int width, int height,
        const char* lineStyle
    );
    ~LineEdit();
};

#endif