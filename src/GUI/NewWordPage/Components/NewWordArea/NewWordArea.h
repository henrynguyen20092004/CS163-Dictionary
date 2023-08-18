#ifndef NEW_WORD_AREA_H
#define NEW_WORD_AREA_H

#include "../../../Components/LineEdit/LineEdit.h"
#include "DefinitionWidget/DefinitionWidget.h"
#include "../../../Components/ScrollLayoutBox/ScrollLayoutBox.h"
#include "../../../Components/VerticalLayoutBox/VerticalLayoutBox.h"

class NewWordArea : public QWidget {
    Q_OBJECT

   private:
    LineEdit *wordInput;
    ScrollLayoutBox *scrollBoxLayout;
    VerticalLayoutBox *mainBox;
    TextLabel *firstLabel;
    Button *addNewWordButton;
    std::vector<DefinitionWidget *> definitionList;
    const char *addButtonStyle =
        "background-color: #D9D9D9; font-size: 24pt; font-weight: 700; "
        "QPushButton::hover { background-color : #09ED12; }";

   private slots:
    void addDefinitionWidget();

   public:
    NewWordArea(QWidget *parent);
    ~NewWordArea();
    bool isWrongFormat();
    bool wordExisted();
    void saveNewWord();

   signals:
    void checkWordAndDefinition();
};

#endif
