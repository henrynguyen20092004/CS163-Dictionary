#include "DefinitionWidget.h"

DefinitionWidget::DefinitionWidget(QWidget* parent, QVBoxLayout*& layout) {
    removeButtonLayout = new QHBoxLayout;
    label = new TextLabel(parent, "Definition:", labelStyle);
    removeButtonLayout->addWidget(label);
    removeButton = new Button(parent, removeOffImageSrc);
    removeButton->setIconSize(QSize(45, 45));
    removeButtonLayout->addWidget(removeButton, 0, Qt::AlignRight);
    layout->addLayout(removeButtonLayout);
    definition = new TextEdit(parent, definitionStyle);
    definition->setFixedHeight(75);
    layout->addWidget(definition);

    CONNECT(removeButton, CLICKED, parent, [=]() {
        emit removeButtonClicked();
    });
    CONNECT(definition, &QTextEdit::textChanged, this, [=]() {
        if (definition->toPlainText().length() > 256) {
            definition->textCursor().deletePreviousChar();
        }
        emit textChanged();
    });
}

TextEdit* DefinitionWidget::getDefinitionInput() { return definition; }

bool DefinitionWidget::isTextEditEmpty() {
    return definition->toPlainText().trimmed().isEmpty();
}

DefinitionWidget::~DefinitionWidget() {
    delete label;
    delete removeButton;
    delete removeButtonLayout;
    delete definition;
}
