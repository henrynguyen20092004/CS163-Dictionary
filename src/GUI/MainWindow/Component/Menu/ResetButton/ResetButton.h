#ifndef RESET_BUTTON_H
#define RESET_BUTTON_H

#include "../../../../Component/Modal/Modal.h"

enum ResetType { CURRENT, ALL };

class ResetButton {
   private:
    Button *resetButton;
    Modal *confirmModal, *successModal, *otherConfirmModal;
    TextLabel *confirmText, *warningText, *successText;

   public:
    ResetButton(QWidget *parent, const char *buttonStyle, ResetType resetType);
    ~ResetButton();
    Modal *getConfirmModal();
    void setOtherConfirmModal(Modal *otherConfirmModal);
};

#endif
