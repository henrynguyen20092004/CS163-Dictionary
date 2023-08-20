#include "NewWordPage.h"

#include "../../GlobalVar/GlobalVar.h"

NewWordPage::NewWordPage() {
    setStyleSheet("font-family: Segoe UI; font-size: 20pt;");

    headerBar = new HeaderBar(this, "NEW WORD");
    newWordArea = new NewWordArea(this);
    saveButton = new Button(this, saveButtonStyle, "SAVE", {527, 666, 192, 40});
    successModal = new SuccessModal(this, "Add a new word successfully!");
    errorLabel = new TextLabel(
        this, "", {320, 664, 668, 36},
        "color: red; font-size: 30px; font-weight: 700;"
    );

    saveButton->hide();
    errorLabel->hide();

    CONNECT(
        newWordArea, &NewWordArea::checkWordAndDefinition, this,
        &NewWordPage::checkWordAndDefinition
    );
    CONNECT(saveButton, CLICKED, [=]() {
        newWordArea->saveNewWord();
        successModal->show();
    });
}

void NewWordPage::checkWordAndDefinition() {
    bool isWrongFormat = newWordArea->isWrongFormat(),
         containWord = newWordArea->wordExisted();

    errorLabel->setText(
        isWrongFormat ? " Some texts may have the wrong format! "
                      : "Word already exists in this dictionary!"
    );
    errorLabel->setVisible(isWrongFormat || containWord);
    saveButton->setVisible(!isWrongFormat && !containWord);
}

NewWordPage::~NewWordPage() {
    delete headerBar;
    delete newWordArea;
    delete saveButton;
    delete successModal;
}
