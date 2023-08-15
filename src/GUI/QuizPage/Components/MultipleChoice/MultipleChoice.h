#ifndef MULTIPLE_CHOICE_H
#define MULTIPLE_CHOICE_H

#include <QRadioButton>

#include "../../../Components/ScrollArea/ScrollArea.h"
#include "../../../Components/TextLabel/TextLabel.h"

class MultipleChoice : public QWidget {
    Q_OBJECT

   private:
    TextLabel *textLabel;
    QWidget *textLabelContainer;
    ScrollArea *scrollArea;
    QRadioButton *radioButton;

   public:
    MultipleChoice(
        QWidget *parent, const QString &text, int posX, int posY, int width,
        int height
    );
    ~MultipleChoice();
    void setText(const QString &text);
    bool isSelected();
};

#endif
