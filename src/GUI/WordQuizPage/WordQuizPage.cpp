#include "WordQuizPage.h"

#include "../../GlobalVar/GlobalVar.h"

WordQuizPage::WordQuizPage() : QuizPage("WORD QUIZ") {}

void WordQuizPage::getNewQuiz() {
    QuizPage::getNewQuiz();

    question->setText(
        "Choose the correct definition for: " +
        currentQuiz.word[currentQuiz.correctOption].first
    );
    question->adjustSize();

    for (int i = 0; i < 4; ++i) {
        choices[i]->setText(
            QString(char(65 + i)) + ". " + currentQuiz.word[i].second
        );
        choices[i]->uncheck();
    }
}
