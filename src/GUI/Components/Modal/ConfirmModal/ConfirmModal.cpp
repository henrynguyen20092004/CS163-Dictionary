#include "ConfirmModal.h"

ConfirmModal *ConfirmModal::instance = nullptr;

ConfirmModal::ConfirmModal(QWidget *parent) : Modal(parent) {
    confirmTextLabel = new TextLabel(this, "", {24, 32, 720, 32});
    warningTextLabel = new TextLabel(
        this, "Warning: All modified data will be lost!", {24, 80, 720, 32},
        "color: #F30404;"
    );
    cancelTextLabel = new TextLabel(
        this, "Cancel",
        {464, MODAL_BUTTON_POS_Y + MODAL_BUTTON_SIZE + MODAL_BUTTON_MARGIN_Y,
         96, MODAL_BUTTON_SIZE}
    );
    cancelButton = new Button(
        this, "assets/XButton.png", MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE, 488,
        MODAL_BUTTON_POS_Y
    );

    okText->setGeometry(
        232, MODAL_BUTTON_POS_Y + MODAL_BUTTON_SIZE + MODAL_BUTTON_MARGIN_Y,
        MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );
    okButton->setGeometry(
        232, MODAL_BUTTON_POS_Y, MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );

    CONNECT(cancelButton, CLICKED, [=]() { hideInstance(); });
}

void ConfirmModal::createInstance(QWidget *parent) {
    if (!instance) {
        instance = new ConfirmModal(parent);
    }
}

ConfirmModal *ConfirmModal::getInstance() { return instance; }

Button *ConfirmModal::getInstanceOkButton() { return instance->okButton; }

QString ConfirmModal::getInstanceConfirmText() {
    return instance->confirmTextLabel->text();
}

void ConfirmModal::setInstanceConfirmText(const QString &confirmText) {
    instance->confirmTextLabel->setText(confirmText);
    showInstance();
}

void ConfirmModal::showInstance() {
    instance->show();
    instance->setOtherWidgetsDisabled(true);
    instance->cancelButton->setAttribute(Qt::WA_TransparentForMouseEvents, false);
}

void ConfirmModal::hideInstance() {
    instance->hide();
    instance->setOtherWidgetsDisabled(false);
}

void ConfirmModal::disconnectInstanceOkButton() {
    instance->okButton->disconnect();
}

void ConfirmModal::deleteInstance() { delete instance; }

ConfirmModal::~ConfirmModal() {
    delete confirmTextLabel;
    delete warningTextLabel;
    delete cancelTextLabel;
    delete cancelButton;
}
