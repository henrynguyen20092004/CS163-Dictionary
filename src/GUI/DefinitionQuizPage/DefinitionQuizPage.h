#ifndef DEFINITION_QUIZ_PAGE
#define DEFINITION_QUIZ_PAGE

#include "../QuizPage/QuizPage.h"

class DefinitionQuizPage : public QuizPage {
   public:
    DefinitionQuizPage();
    void getNewQuiz() override;
};

#endif
