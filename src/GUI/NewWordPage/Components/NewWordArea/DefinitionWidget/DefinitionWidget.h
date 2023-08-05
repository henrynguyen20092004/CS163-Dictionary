#ifndef DEFINITION_WIDGET_H
#define DEFINITION_WIDGET_H

#include <QHBoxLayout>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "../../../../Components/Button/Button.h"
#include "../../../../Components/TextEdit/TextEdit.h"
#include "../../../../Components/TextLabel/TextLabel.h"

class DefinitionWidget : public QWidget {
    Q_OBJECT

   private:
    Button *removeButton;
    TextLabel *label;
    TextEdit *definition;
    QHBoxLayout *removeButtonLayout;
    const char *removeOffImageSrc = "assets/RemoveButton.png";
    const char *labelStyle =
        "color: rgb(255, 255, 255); font: 700 20pt \"Segoe UI\";";
    const char *definitionStyle =
        "background-color: rgb(217, 217, 217); color: rgb(0, 0, 0); font: 400 "
        "20pt \"Segoe UI\";";

   signals:
    void removeButtonClicked();
    void textChanged();

   public:
    TextEdit *getDefinitionInput();

    DefinitionWidget(QWidget *parent, QVBoxLayout *&layout);
    ~DefinitionWidget();
    bool isTextEditEmpty();
};

#endif
