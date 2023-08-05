#include "NewWordArea.h"

#include <algorithm>

NewWordArea::NewWordArea(QWidget* parent) {
    mainWidget = new QWidget(parent);
    mainWidget->setGeometry(134, 71, 1013, 581);
    mainWidget->setStyleSheet(scrollAreaStyle);
    mainLayout = new QVBoxLayout(mainWidget);
    scrollArea = new QScrollArea(mainWidget);
    scrollArea->setStyleSheet(scrollBarStyle);
    scrollArea->setWidgetResizable(true);
    scrollAreaWidget = new QWidget(scrollArea);
    scrollArea->setWidget(scrollAreaWidget);
    scrollAreaLayout = new QVBoxLayout(scrollAreaWidget);
    mainLayout->addWidget(scrollArea);
    firstLabel = new TextLabel(scrollAreaWidget, "New word", firstLabelStyle);
    scrollAreaLayout->addWidget(firstLabel);
    word = new LineEdit(scrollAreaWidget, wordStyle);
    word->setMaxLength(64);
    scrollAreaLayout->addWidget(word);
    DefinitionWidget* newDefinition =
        new DefinitionWidget(scrollAreaWidget, scrollAreaLayout);
    definitions.push_back(newDefinition);
    addNewWordButton =
        new Button(scrollAreaWidget, buttonStyle, "Add a new definition");
    mainLayout->addWidget(addNewWordButton);

    CONNECT(word, &QLineEdit::textChanged, [=]() { emit textChanged(); });
    CONNECT(newDefinition, &DefinitionWidget::removeButtonClicked, [=]() {
        on_removeDefinitionButton_clicked(newDefinition);
    });
    CONNECT(newDefinition, &DefinitionWidget::textChanged, [=]() {
        emit textChanged();
    });
    CONNECT(
        addNewWordButton, CLICKED, this,
        &NewWordArea::on_addDefinitionButton_clicked
    );
}

bool NewWordArea::isTextEditEmpty() {
    if (word->text().trimmed().isEmpty()) {
        return true;
    }
    for (DefinitionWidget*& definition : definitions) {
        if (definition->isTextEditEmpty()) {
            return true;
        }
    }
    return false;
}

void NewWordArea::on_addDefinitionButton_clicked() {
    DefinitionWidget* newDefinition =
        new DefinitionWidget(scrollAreaWidget, scrollAreaLayout);
    definitions.push_back(newDefinition);
    int index = definitions.size() - 1;

    CONNECT(newDefinition, &DefinitionWidget::removeButtonClicked, [=]() {
        on_removeDefinitionButton_clicked(newDefinition);
    });
    CONNECT(newDefinition, &DefinitionWidget::textChanged, [=]() {
        emit textChanged();
    });

    emit buttonClicked();
}

void NewWordArea::on_removeDefinitionButton_clicked(
    DefinitionWidget* newDefinition
) {
    if (definitions.size() == 1) {
        return;
    }

    scrollAreaLayout->removeWidget(newDefinition);
    std::vector<DefinitionWidget*>::iterator it =
        std::find(definitions.begin(), definitions.end(), newDefinition);
    delete *it;
    definitions.erase(it);
    emit buttonClicked();
}

void NewWordArea::clear() {
    word->clear();
    definitions[0]->getDefinitionInput()->clear();

    for (int i = definitions.size() - 1; i >= 0; --i) {
        DefinitionWidget* widget = definitions[i];
        definitions.pop_back();
        delete widget;
    }
}

NewWordArea::~NewWordArea() {
    delete firstLabel;
    delete word;

    for (int i = definitions.size() - 1; i >= 0; --i) {
        DefinitionWidget* widget = definitions[i];
        definitions.pop_back();
        delete widget;
    }

    delete addNewWordButton;
}
