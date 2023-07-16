#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QFrame>
#include <QtWidgets>


class MainWindow : public QMainWindow {
    Q_OBJECT

   private:
    QFrame* headerBar;
    QFrame* backgroundBelowHeaderBar;
    QLabel* labelOnHeaderBar;
    QLineEdit* searchBar;
    QPushButton* lookupButton;
    QPushButton* randomButton;
    QPushButton* cancelButton;
    QPushButton* EE;
    QPushButton* EV;
    QPushButton* VE;
    QPushButton* slangs;
    QPushButton* emoji;
    QPushButton* menuButton;
    QPushButton* switchFromWordToDefintion;
    QPushButton* switchFromDefintionToWord;
    QLabel* logoHCMUS;

    QFrame* menuBar;
    QPushButton* favoriteListButton;
    QPushButton* historyButton;
    QPushButton* definitionQuizButton;
    QPushButton* wordQuizButton;
    QPushButton* addNewWordButton;
    QPushButton* resetButton;

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
   private slots:
    void toggleMenu();
    void toggleCancelButton();
    void clearSearchBar();
};

#endif
