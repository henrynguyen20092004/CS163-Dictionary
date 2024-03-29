#include "QuizPage.h"

#include "../../GlobalVar/GlobalVar.h"

QuizPage::QuizPage(const char *titleText) : Page(titleText) {
    question = new TextLabel(
        content, "", {20, 40, 744, 248}, "font-size: 25px; font-weight: 500;"
    );
    result = new TextLabel(content, "", {232, 508, 316, 28});
    submit = new Button(
        content,
        "background-color: #00B0F0; color:white; font-size: 22px; "
        "border-radius: 10px;",
        "SUBMIT", {304, 540, 172, 50}
    );
    next = new Button(
        content, "background-color:transparent;", "Next >", {712, 8, 72, 30}
    );
    questionScrollArea = new ScrollArea(content, question, 764, 100, 20, 40);

    for (int i = 0; i < 4; ++i) {
        choices[i] = new MultipleChoice(content, "", 46, 152 + 88 * i, 688, 80);
    }

    CONNECT(submit, CLICKED, this, &QuizPage::checkAnswer);
    CONNECT(next, CLICKED, this, [=]() { getNewQuiz(); });
}

void QuizPage::checkAnswer() {
    result->show();
    result->setStyleSheet("color: #FF0E0E;");

    for (int i = 0; i < 4; ++i) {
        if (choices[i]->isSelected()) {
            if (i == currentQuiz.correctOption) {
                result->setText("Correct!");
                result->setStyleSheet("color: #368C17;");
            } else {
                result->setText("Wrong answer, please try again!");
            }

            return;
        }
    }

    result->setText("Please choose an option!");
}

void QuizPage::getNewQuiz() {
    result->hide();
    currentQuiz = GlobalVar::currentDictionary->getFourRandomWords();
}

QuizPage::~QuizPage() {
    delete question;
    delete result;
    delete submit;
    delete next;
    delete questionScrollArea;
    for (int i = 0; i < 4; ++i) {
        delete choices[i];
    }
}
