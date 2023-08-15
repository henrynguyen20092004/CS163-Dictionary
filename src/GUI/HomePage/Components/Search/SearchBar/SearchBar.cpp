#include "SearchBar.h"

#include "../../../../../API/Dictionary/Dictionary.h"
#include "../../../../../GlobalVar/GlobalVar.h"
#include "../../WordDefinitionButton/WordDefinitionButton.h"

SearchBar::SearchBar(QWidget* parent) : QWidget(parent) {
    setGeometry(256, 88, 972, 52);

    lineEdit = new LineEdit(
        this,
        "background-color: #FDFDFD; color: #176B87; "
        "font-weight: 600; padding-left: 12px;",
        {0, 0, 972, 52}
    );
    searchButton = new Button(this, "assets/LookUpButton.png", 36, 36, 872, 8);
    randomButton = new Button(this, "assets/RandomButton.png", 36, 36, 916, 8);

    CONNECT(lineEdit, &QLineEdit::returnPressed, this, &SearchBar::showResults);
    CONNECT(searchButton, CLICKED, this, &SearchBar::showResults);
    CONNECT(randomButton, CLICKED, this, &SearchBar::randomWord);
}

std::vector<QString> SearchBar::search() {
    if (WordDefinitionButton::searchMode) {
        return GlobalVar::currentDictionary->getKeywordFromSubDefinition(
            lineEdit->text()
        );
    }

    return GlobalVar::currentDictionary->getKeywordFromSubKeyword(
        lineEdit->text()
    );
}

void SearchBar::randomWord() {
    lineEdit->setText(GlobalVar::currentDictionary->getRandomWord().first);
}

LineEdit* SearchBar::getLineEdit() { return lineEdit; }

SearchBar::~SearchBar() {
    delete lineEdit;
    delete searchButton;
    delete randomButton;
}
