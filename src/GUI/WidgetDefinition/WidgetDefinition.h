#ifndef WIDGETDEFINITION_H
#define WIDGETDEFINITION_H

#include <QLineEdit>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QScrollBar>
#include <QWidget>

class WidgetDefinition : public QWidget {
    Q_OBJECT

   private:
    QFrame* headerBar;
    QFrame* contentFrame;
    QLabel* labelOnHeaderBar;
    QLineEdit* wordBar;
    QPushButton* returnHomePageButton;
    QPushButton* deleteWordButton;
    QPushButton* favoriteButton;
    QScrollBar* scrollBar;

   public:
    WidgetDefinition(QWidget* parent = nullptr);
    ~WidgetDefinition();
};

#endif
