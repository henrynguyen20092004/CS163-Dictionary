#ifndef NEW_WORD_PAGE_H
#define NEW_WORD_PAGE_H

#include <QScrollArea>
#include <QWidget>

#include "../Components/Modal/Modal.h"
#include "../MainWindow/Components/HeaderBar/HeaderBar.h"
#include "Components/NewWordArea/NewWordArea.h"

class NewWordPage : public QWidget {
    Q_OBJECT

   private:
    HeaderBar* headerBar;
    NewWordArea* newWordArea;
    Button* saveButton;
    Modal* successModal;
    TextLabel* successText;
    TextLabel* warningMessage;
    const char* buttonStyle =
        "QPushButton {background-color: #119ECD; border-radius: 10px; color: "
        "white; font-size: 26px; font-weight: 700;} QPushButton::hover "
        "{background-color: #09ED12;}";
    const char* warningMessageStyle =
        "QLabel {color: red; font-size: 30px; font-weight: 700;}";
    void saveButtonIsEnabled();
    void on_saveButton_clicked();

   public:
    NewWordPage(QWidget* parent = nullptr);
    ~NewWordPage();
};

#endif
