#include "WordDefinitionPage.h"

WordDefinitionPage::WordDefinitionPage() : Page("") {
    wordLabel = new TextLabel(
        content, "", {36, 48, 720, 60},
        "background-color: #D9D9D9; font-size: 24px; font-weight: 700;"
    );
    addDefinitionLabel = new TextLabel(
        content, "Add a definition", {80, 0, 160, 20},
        "color: white; font-weight: 700;"
    );
    addButton = new Button(content, "assets/AddButton.png", 32, 32, 36);
    deleteButton =
        new Button(content, "assets/DeleteButton.png", 36, 36, 36, 8);
    favoriteButton =
        new Button(content, "assets/FavoriteButtonOff.png", 36, 36, 704, 60);
}

void WordDefinitionPage::setWord(const QString& word, Dictionary* dictionary) {
    headerBar->setTitle(word);
    wordLabel->setText(word);

    for (Definition* definition : definitions) {
        delete definition;
    }

    definitions.clear();

    std::vector<QString> wordDefinitions = dictionary->getDefinition(word);
    int n = wordDefinitions.size();

    for (int i = 0; i < n; ++i) {
        definitions.push_back(new Definition(content, wordDefinitions[i], i));
    }

    content->resize(
        content->width(), FIRST_DEFINITION_Y + DEFINITION_HEIGHT * n + 48
    );
    addButton->move(addButton->x(), FIRST_DEFINITION_Y + DEFINITION_HEIGHT * n);
    addDefinitionLabel->move(
        addDefinitionLabel->x(), FIRST_DEFINITION_Y + DEFINITION_HEIGHT * n + 8
    );
}

WordDefinitionPage::~WordDefinitionPage() {
    delete wordLabel;
    delete addDefinitionLabel;
    delete addButton;
    delete deleteButton;
    delete favoriteButton;

    for (Definition* definition : definitions) {
        delete definition;
    }
}
