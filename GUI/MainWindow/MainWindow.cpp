#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) {
    setWindowTitle("CSD");
    setMinimumWidth(400);
    setMinimumHeight(400);
    setContentsMargins(6, 6, 6, 6);

    test = new QLabel;
    test->setText(QString::fromStdWString(L"Ngài Lỏd Thắng Khê vippro"));
    test->setWordWrap(true);
    setCentralWidget(test);
}

MainWindow::~MainWindow() { delete test; }
