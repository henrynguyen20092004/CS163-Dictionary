#include "Modal.h"

Modal::Modal(QWidget* parent) : QWidget(parent) {
    setGeometry(256, 152, 768, 416);
    setStyleSheet("font-size: 28px; font-weight: 700;");
    hide();

    background =
        new Frame(this, "background-color: #D9D9D9;", {0, 0, 768, 416});
    okText = new TextLabel(this, "OK");
    okButton = new Button(
        this, "assets/OKButton.png", MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );
}

Modal::~Modal() {
    delete background;
    delete okText;
    delete okButton;
}
