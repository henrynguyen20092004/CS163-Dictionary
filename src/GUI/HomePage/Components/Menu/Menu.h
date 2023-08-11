#ifndef MENU_H
#define MENU_H

#include "ResetButton/ResetButton.h"

#define BUTTON_NUMBER 5

class Menu : public QWidget {
   private:
    ResetButton *resetCurrentDictionaryButton, *resetAllDictionariesButton;
    Button *buttons[BUTTON_NUMBER], *toggleButton;
    const char *buttonNames[BUTTON_NUMBER]{
        "Favorite list", "Searched history", "Definition quiz", "Word quiz",
        "Add a new word"},
        *buttonStyle =
            "QPushButton {background-color: #64CCC5; border-radius: 10px; "
            "font-size: 20px; font-weight: 500;} QPushButton::hover "
            "{background-color: #09ED12;}",
        *toggleOnImageSrc = "assets/ToggleMenuOnButton.png",
        *toggleOffImageSrc = "assets/ToggleMenuOffButton.png";

   public:
    Menu(QWidget *parent);
    ~Menu();
    void toggle();
};

#endif
