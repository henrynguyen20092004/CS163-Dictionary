#include "SuccessModal.h"

SuccessModal *SuccessModal::instance = nullptr;

SuccessModal::SuccessModal(QWidget *parent) : Modal(parent) {
    successTextLabel = new TextLabel(this, "", {24, 80, 720, 32});

    okText->setGeometry(
        360, MODAL_BUTTON_POS_Y + MODAL_BUTTON_SIZE + MODAL_BUTTON_MARGIN_Y,
        MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );
    okButton->setGeometry(
        360, MODAL_BUTTON_POS_Y, MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );

    CONNECT(okButton, CLICKED, [=]() { hideInstance(); });
}

void SuccessModal::createInstance(QWidget *parent) {
    if (!instance) {
        instance = new SuccessModal(parent);
    }
}

SuccessModal *SuccessModal::getInstance() { return instance; }

void SuccessModal::setInstanceSuccessText(const QString &successText) {
    instance->successTextLabel->setText(successText);
    showInstance();
}

void SuccessModal::showInstance() {
    instance->show();
    instance->setOtherWidgetsDisabled(true);
}

void SuccessModal::hideInstance() {
    instance->hide();
    instance->setOtherWidgetsDisabled(false);
}

void SuccessModal::deleteInstance() { delete instance; }

SuccessModal::~SuccessModal() { delete successTextLabel; }
