#include "SearchBar.h"

SearchBar::SearchBar(QWidget* parent) {
    lineEdit = new LineEdit(
        parent, 253, 88, 973, 54,
        "background-color: #FDFDFD; color: #176B87; font-size: 20px; "
        "font-weight: 600;"
    );
    randomButton =
        new Button(parent, "assets/RandomButton.png", 1128, 96, 36, 36);
    searchButton =
        new Button(parent, "assets/LookUpButton.png", 1171, 96, 47, 39);
}

SearchBar::~SearchBar() {
    delete lineEdit;
    delete randomButton;
    delete searchButton;
}
