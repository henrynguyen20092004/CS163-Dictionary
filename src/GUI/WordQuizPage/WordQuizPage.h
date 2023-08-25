#ifndef WORD_QUIZ_PAGE_H
#define WORD_QUIZ_PAGE_H

#include "../QuizPage/QuizPage.h"

class WordQuizPage : public QuizPage {
   public:
    WordQuizPage();
    void getNewQuiz() override;
};

#endif
