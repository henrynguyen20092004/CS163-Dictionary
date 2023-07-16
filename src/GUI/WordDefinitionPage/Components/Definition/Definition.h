#ifndef DEFINITION_H
#define DEFINITION_H

#include "../../../Components/Button/Button.h"
#include "../../../Components/ScrollArea/ScrollArea.h"
#include "../../../Components/TextLabel/TextLabel.h"

#define DEFINITION_HEIGHT 136
#define FIRST_DEFINITION_Y 136

class Definition : public QWidget {
   private:
    TextLabel *definitionLabel;
    Button *updateButton;
    ScrollArea *definitionScrollArea;

   public:
    Definition(QWidget *parent, const QString &definition, int index);
    ~Definition();
};

#endif
