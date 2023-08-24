#include "EditWord.h"

EditWord::EditWord(QWidget* parent, QWidget* page) {
    addDefinitionLabel = new TextLabel(
        parent, "Add a definition", {62, 524, 180, 36},
        "color: white; font-weight: 700;"
    );
    errorLabel = new TextLabel(
        parent, "", {80, 560, 668, 36}, "color: red; font-weight: 700;"
    );
    addButton = new Button(parent, "assets/AddButton.png", 32, 32, 32, 524);
    saveButton =
        new Button(parent, saveButtonStyle, "SAVE", {340, 560, 120, 30});
    discardButton =
        new Button(parent, "assets/DiscardButton.png", 32, 32, 384, 524);
    definitionArea = new DefinitionArea(parent);
    successModal = new SuccessModal(page, "Word successfully updated!");

    saveButton->hide();
    discardButton->hide();
    errorLabel->hide();

    CONNECT(addButton, CLICKED, [=]() {
        definitionArea->addNewDefinition();
        checkDefinition();
    });
    CONNECT(definitionArea, &DefinitionArea::checkDefinition, [=]() {
        checkDefinition();
    });
}

void EditWord::checkDefinition() {
    if (!discardButton->isVisible()) {
        discardButton->show();
    }

    bool isWrongFormat = definitionArea->isWrongFormat(),
         isEditStateOn = definitionArea->isEditStateOn();

    if (isWrongFormat) {
        errorLabel->setText("Some texts may have the wrong format!");
    } else if (isEditStateOn) {
        errorLabel->setText(" Click all check buttons to confirm! ");
    }

    errorLabel->setVisible(isWrongFormat || isEditStateOn);
    saveButton->setVisible(!isWrongFormat && !isEditStateOn);
}

void EditWord::setWord(const QString& word) {
    definitionArea->setDefinitions(word);
    saveButton->disconnect();
    discardButton->disconnect();
    saveButton->hide();
    errorLabel->hide();
    discardButton->hide();

    CONNECT(saveButton, CLICKED, [=]() {
        definitionArea->saveDefinitions(word);
        successModal->show();
        saveButton->hide();
        discardButton->hide();
    });
    CONNECT(discardButton, CLICKED, [=]() {
        definitionArea->setDefinitions(word);
        saveButton->hide();
        discardButton->hide();
        errorLabel->hide();
    });
}

EditWord::~EditWord() {
    delete addDefinitionLabel;
    delete errorLabel;
    delete addButton;
    delete saveButton;
    delete discardButton;
    delete successModal;
    delete definitionArea;
}
