#include "MultipleChoice.h"

#define SCROLL_BAR_WIDTH 20
#define TEXT_MARGIN_LEFT 88

MultipleChoice::MultipleChoice(
    QWidget *parent, const QString &text, int posX, int posY, int width,
    int height
)
    : QWidget(parent) {
    setGeometry(posX, posY, width, height);

    textLabelContainer = new QWidget(this);
    textLabel = new TextLabel(
        textLabelContainer, text,
        {8, 8, width - SCROLL_BAR_WIDTH - TEXT_MARGIN_LEFT, 248},
        "font-weight: 400;"
    );
    scrollArea = new ScrollArea(
        this, textLabelContainer, width, height, TEXT_MARGIN_LEFT
    );
    radioButton = new QRadioButton(parent);

    textLabel->setAlignment(Qt::AlignLeft);
    textLabelContainer->setGeometry(
        TEXT_MARGIN_LEFT, 0, width - SCROLL_BAR_WIDTH - TEXT_MARGIN_LEFT, 248
    );
    scrollArea->setStyleSheet("background-color: #D9D9D9;");
    radioButton->setGeometry(posX, posY + 16, 48, 48);
    radioButton->setStyleSheet(
        "QRadioButton::indicator {width: 48px; height: 48px; image: "
        "url(assets/RadioButtonUnchecked.png);} "
        "QRadioButton::indicator::checked {image: "
        "url(assets/RadioButtonChecked.png);}"
    );
}

void MultipleChoice::setText(const QString &text) {
    textLabel->setText(text);
    textLabel->adjustSize();
    textLabelContainer->adjustSize();
}

void MultipleChoice::uncheck() {
    radioButton->setAutoExclusive(false);
    radioButton->setChecked(false);
    radioButton->setAutoExclusive(true);
}

bool MultipleChoice::isSelected() { return radioButton->isChecked(); }

MultipleChoice::~MultipleChoice() {
    delete textLabel;
    delete textLabelContainer;
    delete scrollArea;
    delete radioButton;
}
