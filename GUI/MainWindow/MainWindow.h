#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtWidgets>

class MainWindow : public QMainWindow {
   private:
    QLabel* test;

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
};

#endif
