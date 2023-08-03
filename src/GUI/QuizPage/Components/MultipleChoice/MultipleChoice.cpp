#include "MultipleChoice.h"

#define SCROLL_BAR_WIDTH 20
#define TEXT_MARGIN_LEFT 88

MultipleChoice::MultipleChoice(
    QWidget *parent, const QString &text, int posX, int posY, int width,
    int height
)
    : QWidget(parent) {
    setGeometry(posX, posY, width, height);

    textLabel = new TextLabel(
        this, text,
        {TEXT_MARGIN_LEFT, 0, width - SCROLL_BAR_WIDTH - TEXT_MARGIN_LEFT, 248},
        "font-size: 20px; font-weight: 400;"
    );

    scrollArea =
        new ScrollArea(this, textLabel, width, height, TEXT_MARGIN_LEFT);
    radioButton = new QRadioButton(parent);

    textLabel->setAlignment(Qt::AlignLeft);
    scrollArea->setStyleSheet("background-color: #D9D9D9;");
    radioButton->setGeometry(posX, posY + 16, 48, 48);
    radioButton->setStyleSheet(
        "QRadioButton::indicator {width:50px; height:50px; image:"
        "url(assets/Choice.png);} QRadioButton::indicator::checked {image: "
        "url(assets/CurrentChoice.png);}"
    );
}

void MultipleChoice::setText(const QString &text) {
    textLabel->setText(text);
    textLabel->adjustSize();
}

bool MultipleChoice::isSelected() { return radioButton->isChecked(); }

MultipleChoice::~MultipleChoice() {
    delete textLabel;
    delete scrollArea;
    delete radioButton;
}
