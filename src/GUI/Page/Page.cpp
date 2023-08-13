#include "Page.h"

Page::Page(const char *titleText) : QWidget(nullptr) {
    setStyleSheet(mainStyle);

    headerBar = new HeaderBar(this, titleText);
    content = new QWidget(this);
    scrollArea = new ScrollArea(this, content, 800, 600, 240, 60);

    content->setGeometry(240, 60, 780, 600);
    scrollArea->setStyleSheet("background: #9196A7;");
}

Page::~Page() {
    delete headerBar;
    delete content;
    delete scrollArea;
}
