#include "DefinitionQuizPage.h"

#include "../../GlobalVar/GlobalVar.h"

DefinitionQuizPage::DefinitionQuizPage() : QuizPage("DEFINITION QUIZ") {
    getNewQuiz();
    CONNECT(next, CLICKED, this, DefinitionQuizPage::getNewQuiz);
}

void DefinitionQuizPage::getNewQuiz() {
    result->hide();
    currentQuiz = GlobalVar::currentDictionary->getFourRandomWords();

    question->setText(
        "Choose the correct word for: " +
        currentQuiz.word[currentQuiz.correctOption].second
    );
    question->adjustSize();

    for (int i = 0; i < 4; ++i) {
        choices[i]->setText(
            QString(char(65 + i)) + ". " + currentQuiz.word[i].first
        );
        choices[i]->uncheck();
    }
}
