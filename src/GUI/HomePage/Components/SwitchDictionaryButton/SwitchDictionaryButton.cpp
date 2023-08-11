#include "SwitchDictionaryButton.h"

#include "../../../../GlobalVar/GlobalVar.h"

SwitchDictionaryButton::SwitchDictionaryButton(QWidget* parent) {
    EEButton = new Button(
        parent, activeButtonStyle, "English - English", {256, 158, 174, 42}
    );
    VEButton = new Button(
        parent, buttonStyle, "Vietnamese - English", {448, 158, 174, 42}
    );
    EVButton = new Button(
        parent, buttonStyle, "English - Vietnamese", {640, 158, 174, 42}
    );
    slangButton = new Button(parent, buttonStyle, "Slang", {832, 158, 174, 42});
    emojiButton =
        new Button(parent, buttonStyle, "Emoji", {1024, 158, 174, 42});

    CONNECT(EEButton, CLICKED, [=]() { setCurrentDictionary(EE); });
    CONNECT(VEButton, CLICKED, [=]() { setCurrentDictionary(VE); });
    CONNECT(EVButton, CLICKED, [=]() { setCurrentDictionary(EV); });
    CONNECT(slangButton, CLICKED, [=]() { setCurrentDictionary(SLANG); });
    CONNECT(emojiButton, CLICKED, [=]() { setCurrentDictionary(EMOJI); });
}

void SwitchDictionaryButton::setCurrentDictionary(
    DictionaryName newDictionaryName
) {
    if (dictionaryName == newDictionaryName) {
        return;
    }

    switch (dictionaryName) {
        case EE:
            EEButton->setStyleSheet(buttonStyle);
            break;

        case VE:
            VEButton->setStyleSheet(buttonStyle);
            break;

        case EV:
            EVButton->setStyleSheet(buttonStyle);
            break;

        case SLANG:
            slangButton->setStyleSheet(buttonStyle);
            break;

        case EMOJI:
            emojiButton->setStyleSheet(buttonStyle);
            break;
    }

    dictionaryName = newDictionaryName;

    switch (newDictionaryName) {
        case EE:
            GlobalVar::currentDictionary = &GlobalVar::data.DictEE;
            EEButton->setStyleSheet(activeButtonStyle);
            break;

        case VE:
            GlobalVar::currentDictionary = &GlobalVar::data.DictVE;
            VEButton->setStyleSheet(activeButtonStyle);
            break;

        case EV:
            GlobalVar::currentDictionary = &GlobalVar::data.DictEV;
            EVButton->setStyleSheet(activeButtonStyle);
            break;

        case SLANG:
            GlobalVar::currentDictionary = &GlobalVar::data.DictSlang;
            slangButton->setStyleSheet(activeButtonStyle);
            break;

        case EMOJI:
            GlobalVar::currentDictionary = &GlobalVar::data.DictEmoji;
            emojiButton->setStyleSheet(activeButtonStyle);
            break;
    }
}

SwitchDictionaryButton::~SwitchDictionaryButton() {
    delete EEButton;
    delete VEButton;
    delete EVButton;
    delete slangButton;
    delete emojiButton;
}