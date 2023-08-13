#ifndef DEFINITION_WIDGET_H
#define DEFINITION_WIDGET_H

#include <QBoxLayout>

#include "../../../../Components/Button/Button.h"
#include "../../../../Components/TextEdit/TextEdit.h"
#include "../../../../Components/TextLabel/TextLabel.h"

class DefinitionWidget : public QWidget {
    Q_OBJECT

   private:
    Button *removeButton;
    TextLabel *label;
    TextEdit *definitionInput;
    QHBoxLayout *removeButtonLayout;

   public:
    DefinitionWidget(QWidget *parent, QVBoxLayout *layout);
    ~DefinitionWidget();
    Button *getRemoveButton();
    QString getDefinition();
    void clearDefinitionInput();
    bool isWrongFormat();

   signals:
    void textChanged();
};

#endif
