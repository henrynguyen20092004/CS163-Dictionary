#ifndef HEADER_BAR_H
#define HEADER_BAR_H

#include "../../../Component/TextLabel/TextLabel.h"

#define HEADER_BAR_HEIGHT 48

class HeaderBar : public QWidget {
   private:
    TextLabel* textLabel;

   public:
    HeaderBar(QWidget* parent);
    ~HeaderBar();
};

#endif
