#include "NewWordArea.h"

#include <QRegularExpression>

#include "../../../../GlobalVar/GlobalVar.h"

NewWordArea::NewWordArea(QWidget* parent) : QWidget(parent) {
    setStyleSheet("color: white; font-size: 27pt; font-weight: 700;");

    mainBox = new VerticalLayoutBox(
        parent, "background-color: #828799;", {134, 70, 1012, 580}
    );
    scrollBoxLayout = new ScrollLayoutBox(mainBox);
    firstLabel = new TextLabel(
        scrollBoxLayout->getContainer(), "New word",
        "font-size: 27pt; font-weight: 700; color: white;"
    );
    keyWordInput = new LineEdit(
        scrollBoxLayout->getContainer(), "background-color: #D9D9D9;"
    );
    addNewWordButton = new Button(
        scrollBoxLayout->getContainer(), addButtonStyle, "Add a new definition"
    );
    scrollBoxLayout->addWidget(firstLabel);
    scrollBoxLayout->addWidget(keyWordInput);
    mainBox->addWidget(scrollBoxLayout);
    mainBox->addWidget(addNewWordButton);

    addNewDefinition();

    CONNECT(keyWordInput, &QLineEdit::textChanged, [=]() {
        emit checkWordAndDefinition();
    });
    CONNECT(addNewWordButton, CLICKED, this, &NewWordArea::addNewDefinition);
}

bool NewWordArea::isWrongFormat() {
    QString word = keyWordInput->text().trimmed();
    if (word.isEmpty() || (GlobalVar::currentDictionary->dictionaryName != VE &&
                           word.normalized(QString::NormalizationForm_D)
                               .contains(QRegularExpression("\\p{Mn}+")))) {
        return true;
    }

    for (NewDefinition* definition : definitionList) {
        if (definition->isWrongFormat()) {
            return true;
        }
    }

    return false;
}

bool NewWordArea::wordExisted() {
    return GlobalVar::currentDictionary->containWord(
        keyWordInput->text().trimmed()
    );
}

void NewWordArea::addNewDefinition() {
    NewDefinition* newDefinition = new NewDefinition(
        scrollBoxLayout->getContainer(), scrollBoxLayout->getLayout()
    );

    definitionList.push_back(newDefinition);

    CONNECT(newDefinition->getRemoveButton(), CLICKED, [=]() {
        if (definitionList.size() == 1) {
            return;
        }

        std::vector<NewDefinition*>::iterator it = std::find(
            definitionList.begin(), definitionList.end(), newDefinition
        );

        delete *it;
        definitionList.erase(it);
        emit checkWordAndDefinition();
    });

    CONNECT(newDefinition, &NewDefinition::textChanged, [=]() {
        emit checkWordAndDefinition();
    });

    emit checkWordAndDefinition();
}

void NewWordArea::saveNewWord() {
    QString word = keyWordInput->text().trimmed();
    std::vector<QString> definitions;

    for (NewDefinition* definition : definitionList) {
        definitions.push_back(definition->getDefinition());
    }

    GlobalVar::currentDictionary->addWordToDictionary(word, definitions);
    keyWordInput->clear();
    definitionList[0]->clearDefinitionInput();

    for (int i = definitionList.size() - 1; i > 0; --i) {
        delete definitionList[i];
        definitionList.pop_back();
    }
}

NewWordArea::~NewWordArea() {
    delete firstLabel;
    delete keyWordInput;
    delete addNewWordButton;

    for (int i = definitionList.size() - 1; i >= 0; --i) {
        delete definitionList[i];
    }

    delete scrollBoxLayout;
}
