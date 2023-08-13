#ifndef CONFIRM_MODAL_H
#define CONFIRM_MODAL_H

#include "../Modal.h"

class ConfirmModal : public Modal {
    Q_OBJECT

   private:
    TextLabel *confirmTextLabel, *warningText, *cancelText;
    Button *cancelButton;

   public:
    ConfirmModal(QWidget *parent, const QString &confirmText);
    ~ConfirmModal();

   signals:
    void okButtonClicked();
};

#endif
