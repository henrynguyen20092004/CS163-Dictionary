#ifndef MODAL_H
#define MODAL_H

#include "../Button/Button.h"
#include "../Frame/Frame.h"
#include "../TextLabel/TextLabel.h"

#define MODAL_BUTTON_SIZE 48
#define MODAL_BUTTON_POS_Y 256
#define MODAL_BUTTON_MARGIN_Y 8

class Modal : public QWidget {
   protected:
    Frame *background;
    TextLabel *okText;
    Button *okButton;

    Modal(QWidget *parent);
    ~Modal();
    void setOtherWidgetsDisabled(bool disabled);

   public:
    Modal(Modal &other) = delete;
    void operator=(const Modal &) = delete;
};

#endif
