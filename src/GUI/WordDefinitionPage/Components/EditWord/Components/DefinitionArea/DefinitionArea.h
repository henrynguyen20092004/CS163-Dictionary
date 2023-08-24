#ifndef DEFINITION_AREA_H
#define DEFINITION_AREA_H

#include "../../../../../Components/ScrollLayoutBox/ScrollLayoutBox.h"
#include "../../../../../Components/VerticalLayoutBox/VerticalLayoutBox.h"
#include "../Definition/Definition.h"

class DefinitionArea : public VerticalLayoutBox {
    Q_OBJECT

   private:
    ScrollLayoutBox* scrollLayoutBox;
    std::vector<Definition*> definitions;

    void clear();
    void connectRemoveDefinition(Definition *definition);

   public:
    DefinitionArea(QWidget* parent);
    ~DefinitionArea();
    void setDefinitions(const QString& word);
    void addNewDefinition();
    void saveDefinitions(const QString& word);
    bool isEditStateOn();
    bool isWrongFormat();

   signals:
    void checkDefinition();
};

#endif
