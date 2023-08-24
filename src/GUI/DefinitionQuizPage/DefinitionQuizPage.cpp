#include "DefinitionQuizPage.h"

#include "../../GlobalVar/GlobalVar.h"

DefinitionQuizPage::DefinitionQuizPage() : QuizPage("DEFINITION QUIZ") {}

void DefinitionQuizPage::getNewQuiz() {
    QuizPage::getNewQuiz();

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
