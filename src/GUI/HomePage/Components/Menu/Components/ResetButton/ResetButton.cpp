#include "ResetButton.h"

#include "../../../../../../API/ResetDictionary/ResetDictionary.h"
#include "../../../../../Components/Modal/ConfirmModal/ConfirmModal.h"
#include "../../../../../Components/Modal/SuccessModal/SuccessModal.h"

ResetButton::ResetButton(
    QWidget *parent, const char *buttonStyle, ResetType resetType
) {
    QString confirmText =
        "Are you sure you want to reset " +
        QString(resetType ? "all dictionaries" : "current dictionary") + '?';
    resetButton = new Button(
        parent, buttonStyle,
        resetType ? "Reset all dictionaries" : "Reset current dictionary",
        {8, 416 + resetType * 80, 224, 64}
    );

    CONNECT(resetButton, CLICKED, [=]() {
        ConfirmModal::setInstanceConfirmText(confirmText);
        connectConfirmModal(resetType);
    });
}

void ResetButton::connectConfirmModal(ResetType resetType) {
    ConfirmModal::disconnectInstanceOkButton();

    CONNECT(ConfirmModal::getInstanceOkButton(), CLICKED, [=]() {
        resetType ? resetAllDictionaries() : resetCurrentDictionary();
        ConfirmModal::hideInstance();
        SuccessModal::setInstanceSuccessText(
            "Dictionar" + QString(resetType ? "ies" : "y") +
            " successfully reset!"
        );
    });
}

ResetButton::~ResetButton() { delete resetButton; }
