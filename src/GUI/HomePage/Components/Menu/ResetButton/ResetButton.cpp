#include "ResetButton.h"

#include "../../../../../API/ResetDictionary/ResetDictionary.h"

ResetButton::ResetButton(
    QWidget *parent, const char *buttonStyle, ResetType resetType
) {
    resetButton = new Button(
        parent, buttonStyle,
        resetType ? "Reset all dictionaries" : "Reset current dictionary",
        {8, 416 + resetType * 80, 224, 64}
    );
    confirmModal = new ConfirmModal(
        parent->parentWidget(),
        "Are you sure you want to reset " +
            QString(resetType ? "all dictionaries" : "current dictionary") + '?'
    );
    successModal = new SuccessModal(
        parent->parentWidget(), "Dictionar" + QString(resetType ? "ies" : "y") +
                                    " successfully resetted!"
    );

    CONNECT(resetButton, CLICKED, [=]() {
        confirmModal->toggle();
        emit hideOtherConfirmModal();
    });
    CONNECT(confirmModal, &ConfirmModal::okButtonClicked, [=]() {
        confirmModal->grabMouse();
        resetType ? resetAllDictionaries() : resetCurrentDictionary();
        confirmModal->releaseMouse();
        confirmModal->toggle();
        successModal->toggle();
    });
}

void ResetButton::hideConfirmModal() {
    if (confirmModal->isVisible()) {
        confirmModal->hide();
    }
}

ResetButton::~ResetButton() {
    delete resetButton;
    delete confirmModal;
    delete successModal;
}
