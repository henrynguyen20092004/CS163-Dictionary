#include "LanguageButton.h"

LanguageButton::LanguageButton(QWidget* parent) {
    EEButton =
        new Button(parent, 253, 158, 174, 42, buttonStyle, "English - English");
    VEButton = new Button(
        parent, 454, 158, 174, 42, buttonStyle, "Vietnamese - English"
    );
    EVButton = new Button(
        parent, 647, 158, 174, 42, buttonStyle, "English - Vietnamese"
    );
    slangButton = new Button(parent, 844, 158, 174, 42, buttonStyle, "Slang");
    emojiButton = new Button(parent, 1041, 158, 174, 42, buttonStyle, "Emoji");
}

LanguageButton::~LanguageButton() {
    delete EEButton;
    delete EVButton;
    delete VEButton;
    delete slangButton;
    delete emojiButton;
}
