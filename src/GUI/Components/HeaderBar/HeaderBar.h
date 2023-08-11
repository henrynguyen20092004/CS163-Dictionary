#ifndef HEADER_BAR_H
#define HEADER_BAR_H

#include <QBoxLayout>

#include "../TextLabel/TextLabel.h"

#define HEADER_BAR_HEIGHT 48

class HeaderBar : public QWidget {
   private:
    TextLabel* title;
    QHBoxLayout* titleLayout;

   public:
    HeaderBar(QWidget* parent, const QString& titleText);
    ~HeaderBar();
    void setTitle(const QString& titleText);
};

#endif
