#ifndef MODAL_H
#define MODAL_H

#include <functional>

#include "../Button/Button.h"
#include "../TextLabel/TextLabel.h"

class Modal : public QWidget {
   private:
    Button *okButton, *cancelButton = nullptr;
    TextLabel *okText, *cancelText = nullptr;

   public:
    Modal(QWidget *parent);
    Modal(QWidget *parent, const std::function<void()> &okButtonFunction);
    ~Modal();
    void initModal(QWidget *parent);
    void toggle();
};

#endif
