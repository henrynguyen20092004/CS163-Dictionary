#include "WordDefinitionButton.h"

WordDefinitionButton::WordDefinitionButton(QWidget *parent) {
    wordDefinitionButton = new Button(
        parent, buttonStyle, "Word -> Definition", {253, 222, 174, 42}
    );
    definitionWordButton = new Button(
        parent, buttonStyle, "Definition -> Word", {450, 222, 174, 42}
    );
}

WordDefinitionButton::~WordDefinitionButton() {
    delete wordDefinitionButton;
    delete definitionWordButton;
}
