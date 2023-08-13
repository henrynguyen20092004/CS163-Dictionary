#ifndef SEARCH_BAR_H
#define SEARCH_BAR_H

#include <vector>

#include "../../../../Components/Button/Button.h"
#include "../../../../Components/LineEdit/LineEdit.h"

class SearchBar : public QWidget {
    Q_OBJECT

   private:
    LineEdit* lineEdit;
    Button *searchButton, *randomButton;

   private slots:
    void randomWord();

   public:
    SearchBar(QWidget* parent);
    ~SearchBar();
    std::vector<QString> search();
    LineEdit* getLineEdit();

   signals:
    void showResults();
};

#endif
