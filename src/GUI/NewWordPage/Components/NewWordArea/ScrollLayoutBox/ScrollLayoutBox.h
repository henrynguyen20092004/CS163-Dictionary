#ifndef SCROLL_LAYOUT_BOX_H
#define SCROLL_LAYOUT_BOX_H

#include <QScrollArea>
#include <QVBoxLayout>

class ScrollLayoutBox : public QScrollArea {
   private:
    QVBoxLayout* layout;
    QWidget* container;
    const char* scrollBarStyle =
        "QScrollBar:vertical {border: none; background: #D1D1D1; width: 10px; "
        "margin: 0px;} QScrollBar::handle:vertical {background: #2b8cbe; "
        "min-height: 20px;} QScrollBar::add-line:vertical, "
        "QScrollBar::sub-line:vertical {height: 0px; subcontrol-position: "
        "bottom; subcontrol-origin: margin;} QScrollBar::add-page:vertical, "
        "QScrollBar::sub-page:vertical {background: none;}";

   public:
    ScrollLayoutBox(QWidget* parent);
    ~ScrollLayoutBox();
    void addWidget(QWidget* widget);
    QVBoxLayout* getLayout();
    QWidget* getContainer();
};

#endif
