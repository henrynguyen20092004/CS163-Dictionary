#ifndef WORD_QUIZ_PAGE_H
#define WORD_QUIZ_PAGE_H

#include "../QuizPage/QuizPage.h"

class WordQuizPage : public QuizPage {
   private:
    void getNewQuiz();

   public:
    WordQuizPage();
};

#endif
