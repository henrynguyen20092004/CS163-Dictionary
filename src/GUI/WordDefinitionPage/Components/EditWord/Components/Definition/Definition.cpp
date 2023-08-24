#include "Definition.h"

#include <QRegularExpression>

#include "../../../../../../GlobalVar/GlobalVar.h"

Definition::Definition(
    const QString &content, QWidget *parent, QVBoxLayout *layout
) {
    buttonLayout = new QHBoxLayout(parent);
    removeButton = new Button(this, "assets/XButton.png", QSize(45, 45));
    editButton = new Button(this, "assets/EditButtonOff.png", QSize(40, 40));
    definitionInput = new TextEdit(
        parent, "background-color: #D9D9D9; font-weight: 400;", content
    );

    buttonLayout->addWidget(editButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(removeButton, 0, Qt::AlignRight);

    definitionInput->setFixedHeight(75);
    definitionInput->setReadOnly(true);

    layout->addLayout(buttonLayout);
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
    editButton->setIcon(QIcon(
        editState ? "assets/EditButtonOff.png" : "assets/EditButtonOn.png"
    ));
    definitionInput->setReadOnly(editState);
    editState = !editState;
}

Button *Definition::getRemoveButton() { return removeButton; }

QString Definition::getDefinition() {
    return definitionInput->toPlainText().trimmed();
}

bool Definition::isEditStateOn() { return editState; }

bool Definition::isWrongFormat() {
    QString definition = definitionInput->toPlainText().trimmed();

    return definition.isEmpty() ||
           (GlobalVar::currentDictionary->dictionaryName != EV &&
            definition.normalized(QString::NormalizationForm_D)
                .contains(QRegularExpression("\\p{Mn}+")));
}

Definition::~Definition() {
    delete removeButton;
    delete editButton;
    delete buttonLayout;
    delete definitionInput;
}
