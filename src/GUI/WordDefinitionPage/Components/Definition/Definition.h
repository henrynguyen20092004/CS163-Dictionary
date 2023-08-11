#ifndef DEFINITION_H
#define DEFINITION_H

#include "../../../Components/Button/Button.h"
#include "../../../Components/TextLabel/TextLabel.h"

#define DEFINITION_HEIGHT 120
#define FIRST_DEFINITION_Y 136

class Definition : public QWidget {
    Q_OBJECT

   private:
    TextLabel *definitionLabel;
    Button *updateButton;

   public:
    Definition(QWidget *parent, const QString &definition, int index);
    ~Definition();
};

#endif
