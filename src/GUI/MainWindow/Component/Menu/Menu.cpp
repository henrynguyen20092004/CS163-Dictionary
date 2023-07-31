#include "Menu.h"

#include "../HeaderBar/HeaderBar.h"

#define BUTTON_WIDTH 224
#define BUTTON_HEIGHT 64
#define BUTTON_MARGIN_X 8
#define BUTTON_MARGIN_Y 16

Menu::Menu(QWidget* parent) {
    setParent(parent);
    setGeometry(
        0, HEADER_BAR_HEIGHT, BUTTON_WIDTH + BUTTON_MARGIN_X * 2,
        720 - HEADER_BAR_HEIGHT
    );
    setStyleSheet("background-color: #CBBDBD;");
    hide();

    resetCurrentDictionaryButton = new ResetButton(this, buttonStyle, CURRENT);
    resetAllDictionariesButton = new ResetButton(this, buttonStyle, ALL);
    toggleButton =
        new Button(parent, toggleOnImageSrc, 0, 0, 48, HEADER_BAR_HEIGHT);

    for (int i = 0; i < BUTTON_NUMBER; i++) {
        buttons[i] = new Button(
            this, BUTTON_MARGIN_X,
            BUTTON_MARGIN_Y * (i + 1) + BUTTON_HEIGHT * i, BUTTON_WIDTH,
            BUTTON_HEIGHT, buttonStyle, buttonNames[i]
        );
    }

    CONNECT(toggleButton, CLICKED, [=]() { toggle(); });
    resetCurrentDictionaryButton->setOtherConfirmModal(
        resetAllDictionariesButton->getConfirmModal()
    );
    resetAllDictionariesButton->setOtherConfirmModal(
        resetCurrentDictionaryButton->getConfirmModal()
    );
}

void Menu::toggle() {
    if (isVisible()) {
        hide();
        toggleButton->setIcon(QIcon(toggleOnImageSrc));
    } else {
        show();
        toggleButton->setIcon(QIcon(toggleOffImageSrc));
    }
}

Menu::~Menu() {
    delete resetCurrentDictionaryButton;
    delete resetAllDictionariesButton;
    delete toggleButton;

    for (int i = 0; i < BUTTON_NUMBER; i++) {
        delete buttons[i];
    }
}
