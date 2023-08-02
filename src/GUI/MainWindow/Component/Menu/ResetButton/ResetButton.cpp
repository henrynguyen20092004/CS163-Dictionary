#include "ResetButton.h"

#include "../../../../../API/ResetDictionary/ResetDictionary.h"

ResetButton::ResetButton(
    QWidget *parent, const char *buttonStyle, ResetType resetType
) {
    resetButton = new Button(
        parent, 8, 416 + resetType * 80, 224, 64, buttonStyle,
        resetType ? "Reset all dictionaries" : "Reset current dictionary"
    );
    confirmModal = new Modal(parent->parentWidget(), [=]() {
        resetType ? resetAllDictionaries() : resetCurrentDictionary();
        confirmModal->toggle();
        successModal->toggle();
    });
    successModal = new Modal(parent->parentWidget());
    confirmText = new TextLabel(
        confirmModal,
        "Are you sure you want to reset " +
            std::string(resetType ? "all dictionaries" : "current dictionary") +
            '?',
        nullptr, 24, 32, 720, 32
    );
    warningText = new TextLabel(
        confirmModal, "(Warning: All modified data will be lost!)",
        "color: #F30404;", 24, 80, 720, 32
    );
    successText = new TextLabel(
        successModal,
        "Dictionar" + std::string(resetType ? "ies" : "y") +
            " successfully resetted!",
        nullptr, 24, 80, 720, 32
    );

    CONNECT(resetButton, CLICKED, [=]() {
        confirmModal->toggle();

        if (otherConfirmModal->isVisible()) {
            otherConfirmModal->hide();
        }
    });
}

Modal *ResetButton::getConfirmModal() { return confirmModal; }

void ResetButton::setOtherConfirmModal(Modal *otherConfirmModal) {
    this->otherConfirmModal = otherConfirmModal;
}

ResetButton::~ResetButton() {
    delete resetButton;
    delete confirmText;
    delete warningText;
    delete successText;
    delete confirmModal;
    delete successModal;
}
