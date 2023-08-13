#ifndef RESET_BUTTON_H
#define RESET_BUTTON_H

#include "../../../../Components/Modal/ConfirmModal/ConfirmModal.h"
#include "../../../../Components/Modal/SuccessModal/SuccessModal.h"

enum ResetType { CURRENT, ALL };

class ResetButton : public QObject {
    Q_OBJECT

   private:
    Button *resetButton;
    ConfirmModal *confirmModal;
    SuccessModal *successModal;

   public:
    ResetButton(QWidget *parent, const char *buttonStyle, ResetType resetType);
    ~ResetButton();
    void hideConfirmModal();

   signals:
    void hideOtherConfirmModal();
};

#endif
