#include "WordDefinitionPage.h"

#include "../../GlobalVar/GlobalVar.h"

WordDefinitionPage::WordDefinitionPage() : Page("") {
    wordLabel = new TextLabel(
        content, "", {36, 48, 720, 60},
        "background-color: #D9D9D9; font-size: 24px; font-weight: 700;"
    );
    addDefinitionLabel = new TextLabel(
        content, "Add a definition", {62, 525, 180, 36},
        "color: white; font-weight: 700;"
    );
    errorText = new TextLabel(
        content, "", {182, 555, 668, 36},
        "color: red; font-size: 20px; font-weight: 700;"
    );

    deleteButton =
        new Button(content, "assets/DeleteButton.png", 36, 36, 36, 8);
    favoriteButton =
        new Button(content, "assets/FavoriteButtonOff.png", 36, 36, 704, 60);
    addButton = new Button(content, "assets/AddButton.png", 32, 32, 32, 525);

    saveButton =
        new Button(content, saveButtonStyle, "SAVE", {310, 555, 150, 30});

    definitionBox = new DefinitionBox(content, "");

    successModal = new SuccessModal(this, "Update word successfully!");

    saveButton->hide();
    errorText->hide();

    CONNECT(addButton, CLICKED, [=]() {
        definitionBox->addNewDefinition();
        checkDefinition();
    });
    CONNECT(
        definitionBox, &DefinitionBox::checkDefinition, this,
        &WordDefinitionPage::checkDefinition
    );
    CONNECT(saveButton, CLICKED, [=]() {
        definitionBox->saveNewDefinitions(wordLabel->text());
        successModal->show();
    });
}

void WordDefinitionPage::checkDefinition() {
    bool isWrongFormat = definitionBox->isWrongFormat();
    bool isEditStateOn = definitionBox->isEditStateOn();

    if (isWrongFormat) {
        errorText->setText("Some texts may have the wrong format!");
    } else if (isEditStateOn) {
        errorText->setText(
            "Please click all the check button to confirm editing!"
        );
    }

    errorText->setVisible(isWrongFormat || isEditStateOn);
    saveButton->setVisible(!isWrongFormat && !isEditStateOn);
}

void WordDefinitionPage::setWord(const QString& word) {
    headerBar->setTitle(word);
    wordLabel->setText(word);
    definitionBox->setDefinitions(word);
}

WordDefinitionPage::~WordDefinitionPage() {
    delete wordLabel;
    delete addDefinitionLabel;
    delete errorText;
    delete addButton;
    delete deleteButton;
    delete favoriteButton;
    delete saveButton;
    delete definitionBox;
    delete successModal;
}
