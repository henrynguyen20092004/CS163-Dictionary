#ifndef SUCCESS_MODAL_H
#define SUCCESS_MODAL_H

#include "../Modal.h"

class SuccessModal : public Modal {
   private:
    TextLabel *successTextLabel;

   public:
    SuccessModal(QWidget *parent, const QString &successText);
    ~SuccessModal();
};

#endif
