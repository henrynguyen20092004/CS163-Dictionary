#include "WordDefinitionButton.h"

Mode WordDefinitionButton::searchMode = WORD_DEFINITION;

WordDefinitionButton::WordDefinitionButton(QWidget* parent) {
    wordDefinitionButton = new Button(
        parent, activeButtonStyle, "Word -> Definition", {256, 222, 174, 42}
    );
    definitionWordButton = new Button(
        parent, buttonStyle, "Definition -> Word", {448, 222, 174, 42}
    );

    CONNECT(wordDefinitionButton, CLICKED, [=]() {
        wordDefinitionButton->setStyleSheet(activeButtonStyle);
        definitionWordButton->setStyleSheet(buttonStyle);
        searchMode = WORD_DEFINITION;
    });
    CONNECT(definitionWordButton, CLICKED, [=]() {
        wordDefinitionButton->setStyleSheet(buttonStyle);
        definitionWordButton->setStyleSheet(activeButtonStyle);
        searchMode = DEFINITION_WORD;
    });
}

WordDefinitionButton::~WordDefinitionButton() {
    delete wordDefinitionButton;
    delete definitionWordButton;
}
