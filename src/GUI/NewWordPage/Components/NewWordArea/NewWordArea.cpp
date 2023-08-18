#include "NewWordArea.h"

#include <QRegularExpression>

#include "../../../../GlobalVar/GlobalVar.h"

NewWordArea::NewWordArea(QWidget* parent) : QWidget(parent) {
    setStyleSheet("color: white; font-size: 27pt; font-weight: 700;");

    mainBox = new VerticalLayoutBox(
        parent, "background-color: #828799;", {134, 70, 1012, 580}
    );
    scrollBoxLayout = new ScrollLayoutBox(mainBox);
    firstLabel =  new TextLabel(
        scrollBoxLayout->getContainer(), "New word",
        "font-size: 27pt; font-weight: 700; color: white;"
    );
    wordInput = new LineEdit(
        scrollBoxLayout->getContainer(), "background-color: #D9D9D9;"
    );
    addNewWordButton = new Button(
        scrollBoxLayout->getContainer(), addButtonStyle, "Add a new definition"
    );
    scrollBoxLayout->addWidget(firstLabel);
    scrollBoxLayout->addWidget(wordInput);
    mainBox->addWidget(scrollBoxLayout);
    mainBox->addWidget(addNewWordButton);

    addDefinitionWidget();

    CONNECT(wordInput, &QLineEdit::textChanged, [=]() {
        emit checkWordAndDefinition();
    });
    CONNECT(addNewWordButton, CLICKED, this, &NewWordArea::addDefinitionWidget);
}

bool NewWordArea::isWrongFormat() {
    QString word = wordInput->text().trimmed();
    if (word.isEmpty() || (GlobalVar::currentDictionary->dictionaryName != VE &&
                           word.normalized(QString::NormalizationForm_D)
                               .contains(QRegularExpression("\\p{Mn}+")))) {
        return true;
    }

    for (DefinitionWidget* definition : definitionList) {
        if (definition->isWrongFormat()) {
            return true;
        }
    }

    return false;
}

bool NewWordArea::wordExisted() {
    return GlobalVar::currentDictionary->containWord(wordInput->text().trimmed()
    );
}

void NewWordArea::addDefinitionWidget() {
    DefinitionWidget* newDefinition = new DefinitionWidget(
        scrollBoxLayout->getContainer(), scrollBoxLayout->getLayout()
    );

    definitionList.push_back(newDefinition);

    CONNECT(newDefinition->getRemoveButton(), CLICKED, [=]() {
        if (definitionList.size() == 1) {
            return;
        }

        std::vector<DefinitionWidget*>::iterator it = std::find(
            definitionList.begin(), definitionList.end(), newDefinition
        );

        delete *it;
        definitionList.erase(it);
        emit checkWordAndDefinition();
    });

    CONNECT(newDefinition, &DefinitionWidget::textChanged, [=]() {
        emit checkWordAndDefinition();
    });

    emit checkWordAndDefinition();
}

void NewWordArea::saveNewWord() {
    QString word = wordInput->text().trimmed();
    std::vector<QString> definitions;

    for (DefinitionWidget* definition : definitionList) {
        definitions.push_back(definition->getDefinition());
    }

    GlobalVar::currentDictionary->addWordToDictionary(word, definitions);
    wordInput->clear();
    definitionList[0]->clearDefinitionInput();

    for (int i = definitionList.size() - 1; i > 0; --i) {
        delete definitionList[i];
        definitionList.pop_back();
    }
}

NewWordArea::~NewWordArea() {
    delete firstLabel;
    delete wordInput;
    delete addNewWordButton;

    for (int i = definitionList.size() - 1; i >= 0; --i) {
        delete definitionList[i];
    }

    delete scrollBoxLayout;
}
