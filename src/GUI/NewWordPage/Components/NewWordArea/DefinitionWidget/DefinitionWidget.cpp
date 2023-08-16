#include "DefinitionWidget.h"

#include <QRegularExpression>

#include "../../../../../GlobalVar/GlobalVar.h"

DefinitionWidget::DefinitionWidget(QWidget* parent, QVBoxLayout* layout) {
    removeButton = new Button(this, "assets/RemoveButton.png", QSize(45, 45));
    label =
        new TextLabel(this, "Definition:", "color: white; font-weight: 700;");
    definitionInput =
        new TextEdit(parent, "background-color: #D9D9D9; font-weight: 400;");
    removeButtonLayout = new QHBoxLayout(parent);

    definitionInput->setFixedHeight(75);
    removeButtonLayout->addWidget(label);
    removeButtonLayout->addWidget(removeButton, 0, Qt::AlignRight);
    layout->addLayout(removeButtonLayout);
    layout->addWidget(definitionInput);

    CONNECT(definitionInput, &QTextEdit::textChanged, this, [=]() {
        if (definitionInput->toPlainText().length() > 576) {
            definitionInput->textCursor().deletePreviousChar();
        }

        emit textChanged();
    });
}

Button* DefinitionWidget::getRemoveButton() { return removeButton; }

QString DefinitionWidget::getDefinition() {
    return definitionInput->toPlainText().trimmed();
}

void DefinitionWidget::clearDefinitionInput() { definitionInput->clear(); }

bool DefinitionWidget::isWrongFormat() {
    QString definition = definitionInput->toPlainText().trimmed();

    return definition.isEmpty() ||
           (GlobalVar::currentDictionary->dictionaryName != EV &&
            definition.normalized(QString::NormalizationForm_D)
                .contains(QRegularExpression("\\p{Mn}+")));
}

DefinitionWidget::~DefinitionWidget() {
    delete label;
    delete removeButton;
    delete removeButtonLayout;
    delete definitionInput;
}
