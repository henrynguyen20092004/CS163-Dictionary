#include "NewDefinition.h"

#include <QRegularExpression>

#include "../../../../GlobalVar/GlobalVar.h"

NewDefinition::NewDefinition(QWidget* parent, QVBoxLayout* layout) {
    removeButton = new Button(this, "assets/XButton.png", QSize(45, 45));
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

Button* NewDefinition::getRemoveButton() { return removeButton; }

QString NewDefinition::getDefinition() {
    return definitionInput->toPlainText().trimmed();
}

void NewDefinition::clearDefinitionInput() { definitionInput->clear(); }

bool NewDefinition::isWrongFormat() {
    QString definition = definitionInput->toPlainText().trimmed();

    return definition.isEmpty() ||
           (GlobalVar::currentDictionary->dictionaryName != EV &&
            definition.normalized(QString::NormalizationForm_D)
                .contains(QRegularExpression("\\p{Mn}+")));
}

NewDefinition::~NewDefinition() {
    delete label;
    delete removeButton;
    delete removeButtonLayout;
    delete definitionInput;
}
