#ifndef DEFINITION_BOX_H
#define DEFINITION_BOX_H

#include "../../../Components/ScrollLayoutBox/ScrollLayoutBox.h"
#include "../../../Components/VerticalLayoutBox/VerticalLayoutBox.h"
#include "../Definition/Definition.h"

class DefinitionBox : public VerticalLayoutBox {
    Q_OBJECT

   private:
    ScrollLayoutBox* scrollLayoutBox;
    std::vector<Definition*> definitions;

   public:
    DefinitionBox(QWidget* parent, const char* widgetStyle);
    ~DefinitionBox();
    void setDefinitions(const QString& word);
    void removeDefinition();
    void addNewDefinition();
    void saveNewDefinitions(const QString& word);

   public slots:
    bool isEditStateOn();
    bool isWrongFormat();

   signals:
    void checkDefinition();
};

#endif
