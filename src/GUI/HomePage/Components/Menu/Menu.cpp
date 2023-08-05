#include "Menu.h"

#include "../../../Components/HeaderBar/HeaderBar.h"

#define BUTTON_WIDTH 224
#define BUTTON_HEIGHT 64
#define BUTTON_MARGIN_X 8
#define BUTTON_MARGIN_Y 16

Menu::Menu(QWidget* parent) : QWidget(parent) {
    setGeometry(
        0, HEADER_BAR_HEIGHT, BUTTON_WIDTH + BUTTON_MARGIN_X * 2,
        720 - HEADER_BAR_HEIGHT
    );

    resetCurrentDictionaryButton = new ResetButton(this, buttonStyle, CURRENT);
    resetAllDictionariesButton = new ResetButton(this, buttonStyle, ALL);
    toggleButton = new Button(parent, toggleOnImageSrc, 48, HEADER_BAR_HEIGHT);

    for (int i = 0; i < BUTTON_NUMBER; i++) {
        buttons[i] = new Button(
            this, buttonStyle, buttonNames[i],
            {BUTTON_MARGIN_X, BUTTON_MARGIN_Y * (i + 1) + BUTTON_HEIGHT * i,
             BUTTON_WIDTH, BUTTON_HEIGHT}
        );
    }

    CONNECT(toggleButton, CLICKED, [=]() { toggle(); });
    CONNECT(
        resetCurrentDictionaryButton, &ResetButton::hideOtherConfirmModal,
        [=]() { resetAllDictionariesButton->hideConfirmModal(); }
    );
    CONNECT(
        resetAllDictionariesButton, &ResetButton::hideOtherConfirmModal,
        [=]() { resetCurrentDictionaryButton->hideConfirmModal(); }
    );
}

void Menu::toggle() {
    if (isVisible()) {
        hide();
        resetCurrentDictionaryButton->hideConfirmModal();
        resetAllDictionariesButton->hideConfirmModal();
        toggleButton->setIcon(QIcon(toggleOnImageSrc));
    } else {
        widget->show();
        toggleButton->setIcon(QIcon(toggleOffImageSrc));
    }
}

Button** Menu::getMenuButtons() { return buttons; }

Menu::~Menu() {
    delete resetCurrentDictionaryButton;
    delete resetAllDictionariesButton;
    delete toggleButton;

    for (int i = 0; i < BUTTON_NUMBER; i++) {
        delete buttons[i];
    }
}
