#include "Definition.h"

#define DEFINITION_X 40
#define UPDATE_BUTTON_SIZE 24

Definition::Definition(QWidget *parent, const QString &definition, int index)
    : QWidget(parent) {
    setGeometry(
        DEFINITION_X, FIRST_DEFINITION_Y + DEFINITION_HEIGHT * index + 20, 720, 96
    );

    definitionLabel = new TextLabel(
        this, definition, {0, UPDATE_BUTTON_SIZE + 8, 700, 248},
        "color: white; font-weight: 500;"
    );
    updateButton = new Button(
        this, "assets/UpdateButton.png", UPDATE_BUTTON_SIZE, UPDATE_BUTTON_SIZE
    );
    definitionScrollArea = new ScrollArea(
        this, definitionLabel, 720, 96, 0, UPDATE_BUTTON_SIZE + 8
    );

    definitionLabel->setAlignment(Qt::AlignLeft);
}

Definition::~Definition() {
    delete definitionLabel;
    delete updateButton;
    delete definitionScrollArea;
}
