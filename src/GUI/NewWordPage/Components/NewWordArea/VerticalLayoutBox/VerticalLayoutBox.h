#ifndef VERTICAL_LAYOUT_BOX_H
#define VERTICAL_LAYOUT_BOX_H

#include <QVBoxLayout>
#include <QWidget>

class VerticalLayoutBox : public QWidget {
   private:
    QVBoxLayout* layout;

   public:
    VerticalLayoutBox(QWidget* parent, const char* widgetStyle, QRect geometry);
    ~VerticalLayoutBox();
    void addWidget(QWidget* widget);
};

#endif
