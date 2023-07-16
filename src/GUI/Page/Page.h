#ifndef PAGE_H
#define PAGE_H

#include "../Components/HeaderBar/HeaderBar.h"
#include "../Components/ScrollArea/ScrollArea.h"

class Page : public QWidget {
   protected:
    HeaderBar *headerBar;
    QWidget *content;
    ScrollArea *scrollArea;
    const char *mainStyle = "font-family: Inter; font-size: 20px;";

   public:
    Page(const char *titleText);
    ~Page();
};

#endif
