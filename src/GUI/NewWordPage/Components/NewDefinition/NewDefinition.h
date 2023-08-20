#ifndef NEW_DEFINITION_H
#define NEW_DEFINITION_H

#include <QBoxLayout>

#include "../../../Components/Button/Button.h"
#include "../../../Components/TextEdit/TextEdit.h"
#include "../../../Components/TextLabel/TextLabel.h"

class NewDefinition : public QWidget {
    Q_OBJECT

   private:
    Button *removeButton;
    TextLabel *label;
    TextEdit *definitionInput;
    QHBoxLayout *removeButtonLayout;

   public:
    NewDefinition(QWidget *parent, QVBoxLayout *layout);
    ~NewDefinition();
    Button *getRemoveButton();
    QString getDefinition();
    void clearDefinitionInput();
    bool isWrongFormat();

   signals:
    void textChanged();
};

#endif
