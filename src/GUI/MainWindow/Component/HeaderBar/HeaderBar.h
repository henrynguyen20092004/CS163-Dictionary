#ifndef HEADER_BAR_H
#define HEADER_BAR_H

#include "../../../Component/Button/Button.h"
#include "../../../Component/Frame/Frame.h"
#include "../../../Component/TextLabel/TextLabel.h"

class HeaderBar {
   private:
    Frame* headerBar;
    TextLabel* textLabel;
    Button* menuButton;

   public:
    HeaderBar(QWidget* parent);
    ~HeaderBar();
};

#endif
