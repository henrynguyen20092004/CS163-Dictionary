#include "NewWordPage.h"

#include "../../GlobalVar/GlobalVar.h"

NewWordPage::NewWordPage(QWidget* parent) {
    headerBar = new HeaderBar(this);
    newWordArea = new NewWordArea(this);
    saveButton = new Button(this, 527, 666, 192.37, 40, buttonStyle, "SAVE");
    saveButton->hide();
    successModal = new Modal(this);
    successModal->hide();
    successText = new TextLabel(
        successModal, "Add a new word successfully!", {200, 150, 720, 32}
    );
    warningMessage = new TextLabel(
        this, "Some of the text may be in wrong format!", {318, 664, 668, 35},
        warningMessageStyle
    );
    warningMessage->hide();

    CONNECT(
        newWordArea, &NewWordArea::textChanged, this,
        &NewWordPage::saveButtonIsEnabled
    );
    CONNECT(
        newWordArea, &NewWordArea::buttonClicked, this,
        &NewWordPage::saveButtonIsEnabled
    );
    CONNECT(saveButton, CLICKED, this, &NewWordPage::on_saveButton_clicked);
}

void NewWordPage::saveButtonIsEnabled() {
    bool isTextEditEmpty = newWordArea->isTextEditEmpty();
    bool find =
        GlobalVar::currentDictionary->find(newWordArea->word->text().trimmed());
    if (isTextEditEmpty || find) {
        if (isTextEditEmpty) {
            warningMessage->setText("Some of the text may be in wrong format!");
        } else {
            warningMessage->setText("Word does exist in this dictionary!");
        }
        warningMessage->show();
        saveButton->hide();
    } else {
        warningMessage->hide();
        saveButton->show();
    }
}

void NewWordPage::on_saveButton_clicked() {
    QString word = newWordArea->word->text().trimmed();
    std::vector<QString> definitions;

    for (DefinitionWidget* widget : newWordArea->definitions) {
        definitions.push_back(
            widget->getDefinitionInput()->toPlainText().trimmed()
        );
    }

    GlobalVar::currentDictionary->addWordToDictionary(word, definitions);
    newWordArea->clear();

    successModal->show();
    warningMessage->hide();
}

NewWordPage::~NewWordPage() {
    delete headerBar;
    delete newWordArea;
    delete saveButton;
    delete successText;
    delete successModal;
}
