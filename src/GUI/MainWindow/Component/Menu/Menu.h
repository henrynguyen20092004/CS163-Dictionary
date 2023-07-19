#ifndef MENU_H
#define MENU_H

#include "../../../Component/Button/Button.h"
#include "../../../Component/Frame/Frame.h"

class Menu {
   private:
    Frame* menuBar;
    Button *favoriteListButton, *historyButton, *definitionQuizButton,
        *wordQuizButton, *addNewWordButton, *resetButton;
    const char* buttonStyle =
        "QPushButton {background-color: #64CCC5; border-radius: 10px; color: "
        "black; font-size: 20px; font-weight: 500;}"
        "QPushButton::hover {background-color: #09ED12;}";

   public:
    Menu(QWidget* parent);
    ~Menu();
};

#endif
