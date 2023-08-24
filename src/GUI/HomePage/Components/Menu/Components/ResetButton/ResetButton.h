#ifndef RESET_BUTTON_H
#define RESET_BUTTON_H

#include "../../../../../Components/Button/Button.h"

enum ResetType { CURRENT, ALL };

class ResetButton : public QObject {
    Q_OBJECT

   private:
    Button *resetButton;

    void connectConfirmModal(ResetType resetType);

   public:
    ResetButton(QWidget *parent, const char *buttonStyle, ResetType resetType);
    ~ResetButton();
};

#endif
