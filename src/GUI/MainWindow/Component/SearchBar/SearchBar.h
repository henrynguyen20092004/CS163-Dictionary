#ifndef SEARCH_BAR_H
#define SEARCH_BAR_H

#include "../../../Component/Button/Button.h"
#include "../../../Component/LineEdit/LineEdit.h"

class SearchBar {
   private:
    LineEdit* lineEdit;
    Button *randomButton, *searchButton;

   public:
    SearchBar(QWidget* parent);
    ~SearchBar();
};

#endif
