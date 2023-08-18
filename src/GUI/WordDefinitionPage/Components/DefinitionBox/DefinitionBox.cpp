#include "DefinitionBox.h"

#include <QRegularExpression>

#include "../../../../GlobalVar/GlobalVar.h"

DefinitionBox::DefinitionBox(QWidget* parent, const char* widgetStyle)
    : VerticalLayoutBox(parent, widgetStyle) {
    scrollLayoutBox = new ScrollLayoutBox(parent);
    addWidget(scrollLayoutBox);
    setGeometry({36, 126, 726, 400});
}

void DefinitionBox::setDefinitions(const QString& word) {
    for (int i = 0; i < definitions.size(); ++i) {
        delete definitions[i];
    }

    definitions.clear();

    std::vector<QString> wordDefinitions =
        GlobalVar::currentDictionary->getDefinition(word);
    GlobalVar::data.history.add(
        {word, GlobalVar::currentDictionary->dictionaryName}
    );
    int n = wordDefinitions.size();

    for (int i = 0; i < n; ++i) {
        Definition* definition = new Definition(
            wordDefinitions[i], scrollLayoutBox->getContainer(),
            scrollLayoutBox->getLayout()
        );

        if (definition->isWrongFormat()) {
            emit checkDefinition();
        }

        CONNECT(definition, &Definition::textChanged, [=]() {
            emit checkDefinition();
        });

        definitions.push_back(definition);
    }

    removeDefinition();
}

void DefinitionBox::removeDefinition() {
    for (Definition* definition : definitions) {
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
}

void DefinitionBox::addNewDefinition() {
    Definition* newDefinition = new Definition(
        "", scrollLayoutBox->getContainer(), scrollLayoutBox->getLayout()
    );

    newDefinition->changeEditState();

    CONNECT(newDefinition, &Definition::textChanged, [=]() {
        emit checkDefinition();
    });

    definitions.push_back(newDefinition);

    removeDefinition();
}

void DefinitionBox::saveNewDefinitions(const QString& word) {
    std::vector<QString> definitionList;

    for (Definition* definition : definitions) {
        definitionList.push_back(definition->getDefinition());
    }

    GlobalVar::currentDictionary->editDefinitionOfWord(word, definitionList);
}

bool DefinitionBox::isEditStateOn() {
    for (Definition* definition : definitions) {
        if (definition->isEditStateOn()) {
            return true;
        }
    }

    return false;
}

bool DefinitionBox::isWrongFormat() {
    for (Definition* definition : definitions) {
        if (definition->isWrongFormat()) {
            return true;
        }
    }

    return false;
}

DefinitionBox::~DefinitionBox() {
    for (int i = definitions.size() - 1; i >= 0; --i) {
        delete definitions[i];
    }

    delete scrollLayoutBox;
}
