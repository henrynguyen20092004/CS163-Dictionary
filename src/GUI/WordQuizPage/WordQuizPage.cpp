#include "WordQuizPage.h"

#include "../../GlobalVar/GlobalVar.h"

WordQuizPage::WordQuizPage() : QuizPage("WORD QUIZ") {
    getNewQuiz();
    CONNECT(next, CLICKED, this, &WordQuizPage::getNewQuiz);
}

void WordQuizPage::getNewQuiz() {
    result->hide();
    currentQuiz = GlobalVar::currentDictionary->getFourRandomWords();

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
