#ifndef LANGUAGE_BUTTON_H
#define LANGUAGE_BUTTON_H

#include "../../../Component/Button/Button.h"

class LanguageButton {
   private:
    Button *EEButton, *VEButton, *EVButton, *slangButton, *emojiButton;
    const char *buttonStyle =
        "QPushButton {background-color: #119ECD; border-radius: 10px; color: "
        "black; font-size: 16px; font-weight: 500;}"
        "QPushButton::hover {background-color: #09ED12;}";

   public:
    LanguageButton(QWidget *parent);
    ~LanguageButton();
};

#endif
