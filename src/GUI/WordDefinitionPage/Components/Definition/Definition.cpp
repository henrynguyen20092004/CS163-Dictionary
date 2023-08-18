#include "Definition.h"

#include <QRegularExpression>

#include "../../../../GlobalVar/GlobalVar.h"

Definition::Definition(
    const QString &content, QWidget *parent, QVBoxLayout *layout
) {
    ButtonLayout = new QHBoxLayout(parent);
    removeButton = new Button(this, "assets/RemoveButton.png", QSize(45, 45));
    editButton = new Button(this, "assets/EditButtonOff.png", QSize(40, 40));
    definitionInput = new TextEdit(
        parent, content, "background-color: #D9D9D9; font-weight: 400;"
    );

    ButtonLayout->addWidget(editButton, 0, Qt::AlignLeft);
    ButtonLayout->addWidget(removeButton, 0, Qt::AlignRight);

    definitionInput->setFixedHeight(75);

    layout->addLayout(ButtonLayout);
    layout->addWidget(definitionInput);

    CONNECT(definitionInput, &QTextEdit::textChanged, this, [=]() {
        if (definitionInput->toPlainText().length() > 576) {
            definitionInput->textCursor().deletePreviousChar();
        }

        emit textChanged();
    });

    CONNECT(editButton, CLICKED, [=]() {
        changeEditState();
        emit textChanged();
    });
}

void Definition::changeEditState() {
    if (isEditStateOn()) {
        editButton->setIcon(QIcon("assets/EditButtonOff.png"));
        definitionInput->setReadOnly(true);
        editState = false;
    } else {
        editButton->setIcon(QIcon("assets/EditButtonOn.png"));
        definitionInput->setReadOnly(false);
        editState = true;
    }
}

Button *Definition::getRemoveButton() { return removeButton; }

QString Definition::getDefinition() {
    return definitionInput->toPlainText().trimmed();
}

bool Definition::isEditStateOn() { return editState; }

bool Definition::isWrongFormat() {
    QString definition = definitionInput->toPlainText().trimmed();

    return definition.isEmpty() ||
           (GlobalVar::currentDictionary->dictionaryName != VE &&
            definition.normalized(QString::NormalizationForm_D)
                .contains(QRegularExpression("\\p{Mn}+")));
}

Definition::~Definition() {
    delete removeButton;
    delete editButton;
    delete ButtonLayout;
    delete definitionInput;
}
