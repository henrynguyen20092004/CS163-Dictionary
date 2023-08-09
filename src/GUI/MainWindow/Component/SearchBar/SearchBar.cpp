#include "SearchBar.h"

SearchBar::SearchBar(QWidget* parent) {
    lineEdit = new LineEdit(
        parent,
        "background-color: #FDFDFD; color: #176B87; font-size: 20px; "
        "font-weight: 600;",
        {256, 88, 972, 54}
    );
    randomButton =
        new Button(parent, "assets/RandomButton.png", 36, 36, 1128, 96);
    searchButton =
        new Button(parent, "assets/LookUpButton.png", 36, 36, 1172, 96);
}

SearchBar::~SearchBar() {
    delete lineEdit;
    delete randomButton;
    delete searchButton;
}
