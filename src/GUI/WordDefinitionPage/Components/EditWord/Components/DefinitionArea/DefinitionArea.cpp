#include "DefinitionArea.h"

#include <QRegularExpression>

#include "../../../../../../GlobalVar/GlobalVar.h"

DefinitionArea::DefinitionArea(QWidget* parent)
    : VerticalLayoutBox(parent, "", {36, 126, 726, 400}) {
    scrollLayoutBox = new ScrollLayoutBox(parent);
    addWidget(scrollLayoutBox);
}

void DefinitionArea::clear() {
    for (Definition* definition : definitions) {
        delete definition;
    }

    definitions.clear();
}

void DefinitionArea::setDefinitions(const QString& word) {
    clear();
    std::vector<QString> wordDefinitions =
        GlobalVar::currentDictionary->getDefinition(word);
    GlobalVar::data.history.add(
        {word, GlobalVar::currentDictionary->dictionaryName}
    );

    for (const QString& wordDefinition : wordDefinitions) {
        Definition* definition = new Definition(
            wordDefinition, scrollLayoutBox->getContainer(),
            scrollLayoutBox->getLayout()
        );

        if (definition->isWrongFormat()) {
            emit checkDefinition();
        }

        CONNECT(definition, &Definition::textChanged, [=]() {
            emit checkDefinition();
        });

        definitions.push_back(definition);
        connectRemoveDefinition(definition);
    }
}

void DefinitionArea::addNewDefinition() {
    Definition* newDefinition = new Definition(
        "", scrollLayoutBox->getContainer(), scrollLayoutBox->getLayout()
    );

    newDefinition->changeEditState();

    CONNECT(newDefinition, &Definition::textChanged, [=]() {
        emit checkDefinition();
    });

    definitions.push_back(newDefinition);
    connectRemoveDefinition(newDefinition);
}

void DefinitionArea::connectRemoveDefinition(Definition* definition) {
    CONNECT(definition->getRemoveButton(), CLICKED, [=]() {
        if (definitions.size() == 1) {
            return;
        }

        std::vector<Definition*>::iterator it =
            std::find(definitions.begin(), definitions.end(), definition);

        delete *it;
        definitions.erase(it);

        emit checkDefinition();
    });
}

void DefinitionArea::saveNewDefinitions(const QString& word) {
    std::vector<QString> definitionList;

    for (Definition* definition : definitions) {
        definitionList.push_back(definition->getDefinition());
    }

    GlobalVar::currentDictionary->editDefinitionOfWord(word, definitionList);
}

bool DefinitionArea::isEditStateOn() {
    for (Definition* definition : definitions) {
        if (definition->isEditStateOn()) {
            return true;
        }
    }

    return false;
}

bool DefinitionArea::isWrongFormat() {
    for (Definition* definition : definitions) {
        if (definition->isWrongFormat()) {
            return true;
        }
    }

    return false;
}

DefinitionArea::~DefinitionArea() {
    clear();
    delete scrollLayoutBox;
}
