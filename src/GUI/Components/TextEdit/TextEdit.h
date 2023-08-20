#ifndef TEXT_EDIT_H
#define TEXT_EDIT_H

#include <QTextEdit>

class TextEdit : public QTextEdit {
   public:
    TextEdit(QWidget* parent, const char* style, const QString& content = "");
};

#endif
