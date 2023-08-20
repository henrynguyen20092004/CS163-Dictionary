#ifndef DEFINITION_H
#define DEFINITION_H

#include <QBoxLayout>

#include "../../../../../Components/Button/Button.h"
#include "../../../../../Components/TextEdit/TextEdit.h"
#include "../../../../../Components/TextLabel/TextLabel.h"

class Definition : public QWidget {
    Q_OBJECT

   private:
    QHBoxLayout *buttonLayout;
    Button *removeButton, *editButton;
    TextEdit *definitionInput;
    bool editState = false;

   public:
    Definition(const QString &content, QWidget *parent, QVBoxLayout *layout);
    ~Definition();
    void changeEditState();
    Button *getRemoveButton();
    QString getDefinition();
    bool isEditStateOn();
    bool isWrongFormat();

   signals:
    void textChanged();
};

#endif
