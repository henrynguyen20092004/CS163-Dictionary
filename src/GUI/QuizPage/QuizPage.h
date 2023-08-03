#ifndef QUIZ_PAGE_H
#define QUIZ_PAGE_H

#include "../../API/Dictionary/Dictionary.h"
#include "../Components/Button/Button.h"
#include "../Components/ScrollArea/ScrollArea.h"
#include "../Page/Page.h"
#include "Components/MultipleChoice/MultipleChoice.h"

class QuizPage : public Page {
   private:
    Button *submit;
    ScrollArea *questionScrollArea;

   private slots:
    void checkAnswer();

   protected:
    TextLabel *question, *result;
    Button *next;
    MultipleChoice *choices[4];
    RandomList currentQuiz;

   public:
    QuizPage();
    ~QuizPage();
};

#endif
