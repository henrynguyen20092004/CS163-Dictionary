#include "WordDefinitionButton.h"

WordDefinitionButton::WordDefinitionButton(QWidget *parent) {
    wordDefinitionButton = new Button(
        parent, 253, 222, 174, 42, buttonStyle, "Word -> Definition"
    );
    definitionWordButton = new Button(
        parent, 450, 222, 174, 42, buttonStyle, "Definition -> Word"
    );
}

WordDefinitionButton::~WordDefinitionButton() {
    delete wordDefinitionButton;
    delete definitionWordButton;
}
