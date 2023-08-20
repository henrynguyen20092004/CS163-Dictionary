#ifndef NEW_WORD_PAGE_H
#define NEW_WORD_PAGE_H

#include "../Components/HeaderBar/HeaderBar.h"
#include "../Components/Modal/SuccessModal/SuccessModal.h"
#include "Components/NewWordArea/NewWordArea.h"

class NewWordPage : public QWidget {
   private:
    HeaderBar* headerBar;
    NewWordArea* newWordArea;
    Button* saveButton;
    SuccessModal* successModal;
    TextLabel* errorLabel;
    const char* saveButtonStyle =
        "QPushButton {background-color: #119ECD; border-radius: "
        "10px; color: white; font-size: 26px; font-weight: 700;} "
        "QPushButton::hover {background-color: #09ED12;}";

   private slots:
    void checkWordAndDefinition();

   public:
    NewWordPage();
    ~NewWordPage();
};

#endif
