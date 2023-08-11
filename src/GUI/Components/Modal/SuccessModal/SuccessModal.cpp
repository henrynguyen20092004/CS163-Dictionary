#include "SuccessModal.h"

SuccessModal::SuccessModal(QWidget *parent, const QString &successText)
    : Modal(parent) {
    successTextLabel = new TextLabel(this, successText, {24, 80, 720, 32});

    okText->setGeometry(
        360, MODAL_BUTTON_POS_Y + MODAL_BUTTON_SIZE + MODAL_BUTTON_MARGIN_Y,
        MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );
    okButton->setGeometry(
        360, MODAL_BUTTON_POS_Y, MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );

    CONNECT(okButton, CLICKED, this, &Modal::toggle);
}

SuccessModal::~SuccessModal() { delete successTextLabel; }
