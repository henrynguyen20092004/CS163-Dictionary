#include "ConfirmModal.h"

ConfirmModal::ConfirmModal(QWidget *parent, const QString &confirmText)
    : Modal(parent) {
    confirmTextLabel = new TextLabel(this, confirmText, {24, 32, 720, 32});
    warningText = new TextLabel(
        this, "Warning: All modified data will be lost!", {24, 80, 720, 32},
        "color: #F30404;"
    );
    cancelText = new TextLabel(
        this, "Cancel",
        {464, MODAL_BUTTON_POS_Y + MODAL_BUTTON_SIZE + MODAL_BUTTON_MARGIN_Y,
         96, MODAL_BUTTON_SIZE}
    );
    cancelButton = new Button(
        this, "assets/Cancel.png", MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE, 488,
        MODAL_BUTTON_POS_Y
    );

    okText->setGeometry(
        232, MODAL_BUTTON_POS_Y + MODAL_BUTTON_SIZE + MODAL_BUTTON_MARGIN_Y,
        MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );
    okButton->setGeometry(
        232, MODAL_BUTTON_POS_Y, MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );

    CONNECT(okButton, CLICKED, this, &ConfirmModal::okButtonClicked);
    CONNECT(cancelButton, CLICKED, this, &Modal::toggle);
}

ConfirmModal::~ConfirmModal() {
    delete confirmTextLabel;
    delete warningText;
    delete cancelText;
    delete cancelButton;
}
