#include "WidgetDefinition.h"

WidgetDefinition::WidgetDefinition(QWidget *parent) : QWidget(parent) {
    headerBar = new QFrame(this);
    headerBar->setGeometry(0, 0, 1280, 50);
    headerBar->setStyleSheet("background-color: #176B87;");
    headerBar->setFrameShape(QFrame::StyledPanel);
    headerBar->setFrameShadow(QFrame::Raised);

    labelOnHeaderBar = new QLabel(this);
    labelOnHeaderBar->setGeometry(416, 16, 447, 21);
    labelOnHeaderBar->setAlignment(Qt::AlignCenter);
    labelOnHeaderBar->setStyleSheet(
        "color: white; font-size: 27px; font-family: Inter; font-weight: 700;"
    );

    returnHomePageButton = new QPushButton("< Back to home page", this);
    returnHomePageButton->setGeometry(11, 15, 279, 21);

    contentFrame = new QFrame(this);
    contentFrame->setGeometry(228, 95, 824, 585);
    contentFrame->setStyleSheet("background-color: #9196A7;");
    contentFrame->setFrameShape(QFrame::StyledPanel);
    contentFrame->setFrameShadow(QFrame::Raised);
}

WidgetDefinition::~WidgetDefinition() {
    delete headerBar;
    delete labelOnHeaderBar;
    delete returnHomePageButton;
    delete contentFrame;
}
