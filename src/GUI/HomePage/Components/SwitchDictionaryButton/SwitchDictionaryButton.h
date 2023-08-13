#ifndef DICTIONARY_SWITCH_BUTTON_H
#define DICTIONARY_SWITCH_BUTTON_H

#include "../../../../API/Dictionary/Dictionary.h"
#include "../../../Components/Button/Button.h"

class SwitchDictionaryButton {
   private:
    Button *EEButton, *VEButton, *EVButton, *slangButton, *emojiButton;
    DictionaryName dictionaryName = EE;
    const char *buttonStyle =
        "QPushButton {background-color: #119ECD; border-radius: 10px; "
        "font-size: 16px; font-weight: 500;} QPushButton::hover "
        "{background-color: #09ED12;}";
    const char *activeButtonStyle =
        "QPushButton {background-color: #09ED12; border-radius: 10px; "
        "font-size: 16px; font-weight: 500;}";

   public:
    SwitchDictionaryButton(QWidget *parent);
    void setCurrentDictionary(DictionaryName newDictionaryName);
    ~SwitchDictionaryButton();
};

#endif
