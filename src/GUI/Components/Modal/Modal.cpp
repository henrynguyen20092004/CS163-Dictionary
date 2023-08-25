#include "Modal.h"

#include <QLineEdit>
#include <QTextEdit>

Modal::Modal(QWidget *parent) : QWidget(parent) {
    setGeometry(256, 152, 768, 416);
    setStyleSheet("font-size: 28px; font-weight: 700;");
    hide();

    background =
        new Frame(this, "background-color: #FFFFFF;", {0, 0, 768, 416});
    okText = new TextLabel(this, "OK");
    okButton = new Button(
        this, "assets/OKButton.png", MODAL_BUTTON_SIZE, MODAL_BUTTON_SIZE
    );
}

void Modal::setOtherWidgetsDisabled(bool disabled) {
    QList<QPushButton *> buttons = parent()->findChildren<QPushButton *>();
    QList<QTextEdit *> textEdits = parent()->findChildren<QTextEdit *>();
    QLineEdit *lineEdit = parent()->findChild<QLineEdit *>();

    for (QPushButton *button : buttons) {
        if (button != okButton) {
            button->setAttribute(Qt::WA_TransparentForMouseEvents, disabled);
        }
    }

    for (QTextEdit *textEdit : textEdits) {
        textEdit->setAttribute(Qt::WA_TransparentForMouseEvents, disabled);
    }

    if (lineEdit) {
        lineEdit->setAttribute(Qt::WA_TransparentForMouseEvents, disabled);
    }
}

Modal::~Modal() {
    delete background;
    delete okText;
    delete okButton;
}
