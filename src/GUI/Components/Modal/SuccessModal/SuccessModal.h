#ifndef SUCCESS_MODAL_H
#define SUCCESS_MODAL_H

#include "../Modal.h"

class SuccessModal : public Modal {
   private:
    TextLabel *successTextLabel;
    static SuccessModal *instance;

    SuccessModal(QWidget *parent);
    ~SuccessModal();

   public:
    static void createInstance(QWidget *parent);
    static SuccessModal *getInstance();
    static void setInstanceSuccessText(const QString &successText);
    static void showInstance();
    static void hideInstance();
    static void deleteInstance();
};

#endif
