#ifndef NEW_WORD_AREA_H
#define NEW_WORD_AREA_H

#include <QScrollArea>
#include <QWidget>

#include "../../../Components/LineEdit/LineEdit.h"
#include "DefinitionWidget/DefinitionWidget.h"

class NewWordArea : public QWidget {
    Q_OBJECT

   private:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidget;
    QVBoxLayout *scrollAreaLayout;
    QWidget *mainWidget;
    QVBoxLayout *mainLayout;
    TextLabel *firstLabel;
    Button *addNewWordButton;
    const char *scrollAreaStyle = "background-color: rgb(130, 135, 153);";
    const char *firstLabelStyle =
        "color: rgb(255, 255, 255); font : 700 27pt \"Segoe UI\";";
    const char *wordStyle =
        "background-color: rgb(217, 217, 217); color : rgb(0, 0, 0); font : "
        "700 27pt \"Segoe UI\";";
    const char *buttonStyle =
        "background-color: rgb(217, 217, 217); color: rgb(0, 0, 0); font: 700 "
        "20pt \"Segoe UI\"; QPushButton::hover { background - color : #09ED12; "
        "}";
    const char *scrollBarStyle =
        "QScrollBar:vertical{border: none;background: #d1d1d1;width: "
        "10px;margin: 0px 0px 0px 0px;}QScrollBar::handle:vertical{background: "
        "#2b8cbe;min-height: "
        "20px;}QScrollBar::add-line:vertical,QScrollBar::sub-line:vertical{"
        "height: 0px;subcontrol-position: bottom;subcontrol-origin: "
        "margin;}QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical "
        "{background: none;}";

    void on_addDefinitionButton_clicked();
    void on_removeDefinitionButton_clicked(DefinitionWidget *newDefinition);
   signals:
    void textChanged();
    void buttonClicked();

   public:
    LineEdit *word;
    std::vector<DefinitionWidget *> definitions;
    NewWordArea(QWidget *parent = nullptr);
    ~NewWordArea();
    bool isTextEditEmpty();
    void clear();
};

#endif
