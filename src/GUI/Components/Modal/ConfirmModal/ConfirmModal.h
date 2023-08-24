#ifndef CONFIRM_MODAL_H
#define CONFIRM_MODAL_H

#include "../Modal.h"

class ConfirmModal : public Modal {
   private:
    TextLabel *confirmTextLabel, *warningTextLabel, *cancelTextLabel;
    Button *cancelButton;
    static ConfirmModal *instance;

    ConfirmModal(QWidget *parent);
    ~ConfirmModal();

   public:
    static void createInstance(QWidget *parent);
    static ConfirmModal *getInstance();
    static Button *getInstanceOkButton();
    static QString getInstanceConfirmText();
    static void setInstanceConfirmText(const QString &confirmText);
    static void showInstance();
    static void hideInstance();
    static void disconnectInstanceOkButton();
    static void deleteInstance();
};

#endif
