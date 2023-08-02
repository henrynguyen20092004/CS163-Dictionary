#include "Modal.h"

#define BUTTON_SIZE 48
#define BUTTON_POS_Y 256
#define BUTTON_MARGIN_Y 16

Modal::Modal(QWidget* parent) {
    initModal(parent);

    okButton = new Button(
        this, "assets/OK.png", 360, BUTTON_POS_Y, BUTTON_SIZE, BUTTON_SIZE
    );
    okText = new TextLabel(
        this, "OK", nullptr, 360, BUTTON_POS_Y + BUTTON_SIZE + BUTTON_MARGIN_Y,
        120, 32
    );

    CONNECT(okButton, CLICKED, [=]() { toggle(); });
}

Modal::Modal(QWidget* parent, const std::function<void()>& okButtonFunction) {
    initModal(parent);

    okButton = new Button(
        this, "assets/OK.png", 232, BUTTON_POS_Y, BUTTON_SIZE, BUTTON_SIZE
    );
    cancelButton = new Button(
        this, "assets/Cancel.png", 488, BUTTON_POS_Y, BUTTON_SIZE, BUTTON_SIZE
    );
    okText = new TextLabel(
        this, "OK", nullptr, 232, BUTTON_POS_Y + BUTTON_SIZE + BUTTON_MARGIN_Y,
        120, 32
    );
    cancelText = new TextLabel(
        this, "Cancel", nullptr, 464,
        BUTTON_POS_Y + BUTTON_SIZE + BUTTON_MARGIN_Y, 120, 32
    );

    CONNECT(okButton, CLICKED, okButtonFunction);
    CONNECT(cancelButton, CLICKED, [=]() { toggle(); });
}

void Modal::initModal(QWidget* parent) {
    setParent(parent);
    setGeometry(256, 152, 768, 416);
    setStyleSheet(
        "background-color: #D9D9D9; font-size: 28px; font-weight: 700;"
    );
    hide();
}

void Modal::toggle() {
    if (isVisible()) {
        hide();
    } else {
        show();
    }
}

Modal::~Modal() {
    delete okButton;
    delete cancelButton;
    delete okText;
    delete cancelText;
}
