#include "Definition.h"

#define DEFINITION_X 40
#define UPDATE_BUTTON_SIZE 24

Definition::Definition(QWidget *parent, const QString &definition, int index)
    : QWidget(parent) {
    definitionLabel = new TextLabel(
        this, definition,
        {DEFINITION_X,
         FIRST_DEFINITION_Y + UPDATE_BUTTON_SIZE + DEFINITION_HEIGHT * index,
         720, 96},
        "color: white; font-weight: 500;"
    );
    updateButton = new Button(
        this, "assets/UpdateButton.png", UPDATE_BUTTON_SIZE, UPDATE_BUTTON_SIZE,
        DEFINITION_X, FIRST_DEFINITION_Y + DEFINITION_HEIGHT * index
    );

    definitionLabel->setAlignment(Qt::AlignLeft);
}

Definition::~Definition() {
    delete definitionLabel;
    delete updateButton;
}
