#ifndef BACK_BUTTON_H
#define BACK_BUTTON_H

#include "../Button/Button.h"

class BackButton : public Button {
   private:
    static BackButton *instance;

    BackButton(QWidget *parent);

   public:
    BackButton(BackButton &other) = delete;
    void operator=(const BackButton &) = delete;
    static void createInstance(QWidget *parent);
    static BackButton *getInstance();
    static void deleteInstance();
};

#endif
