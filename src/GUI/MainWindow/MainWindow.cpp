#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) {
    setWindowTitle("CSD");
    setMinimumWidth(1280);
    setMinimumHeight(720);

    backgroundBelowHeaderBar = new QFrame(this);
    backgroundBelowHeaderBar->setGeometry(0, 0, 1280, 319);
    backgroundBelowHeaderBar->setStyleSheet("background-color: #001C30;");
    backgroundBelowHeaderBar->setFrameShape(QFrame::StyledPanel);
    backgroundBelowHeaderBar->setFrameShadow(QFrame::Raised);

    headerBar = new QFrame(this);
    headerBar->setGeometry(0, 0, 1280, 50);
    headerBar->setStyleSheet("background-color: #176B87;");
    headerBar->setFrameShape(QFrame::StyledPanel);
    headerBar->setFrameShadow(QFrame::Raised);

    labelOnHeaderBar = new QLabel("DICTIONARY", this);
    labelOnHeaderBar->setGeometry(546, 14, 187, 21);
    labelOnHeaderBar->setAlignment(Qt::AlignCenter);
    labelOnHeaderBar->setStyleSheet(
        "color: white; font-size: 27px; font-family: Inter; font-weight: 700;"
    );
    labelOnHeaderBar->setWordWrap(true);

    searchBar = new QLineEdit(this);
    searchBar->setGeometry(253, 88, 973, 54);
    searchBar->setStyleSheet(
        "background-color: #FDFDFD; color: #176B87; font-size: 20px; "
        "font-family: Inter; font-weight: 600;"
    );

    menuButton = new QPushButton(this);
    menuButton->setGeometry(0, 0, 60, 50);
    menuButton->setIcon(QIcon("assets/Menu.png"));
    menuButton->setIconSize(QSize(60, 50));

    lookupButton = new QPushButton(this);
    lookupButton->setGeometry(1171, 96, 47, 39);
    lookupButton->setIcon(QIcon("assets/Lookup button.png"));
    lookupButton->setIconSize(QSize(47, 39));

    logoHCMUS = new QLabel(this);
    logoHCMUS->setGeometry(30, 88, 188, 150);
    QPixmap placeholderImage("assets/logo-khtn-1.png");
    logoHCMUS->setPixmap(placeholderImage);

    randomButton = new QPushButton(this);
    randomButton->setGeometry(1128, 96, 36, 36);
    randomButton->setIcon(QIcon("assets/Random button.png"));
    randomButton->setIconSize(QSize(36, 36));

    cancelButton = new QPushButton(this);
    cancelButton->setGeometry(1128, 101, 26, 26);
    cancelButton->setIcon(QIcon("assets/Cancel button.png"));
    cancelButton->setIconSize(QSize(26, 26));
    cancelButton->hide();

    EE = new QPushButton("English - English", this);
    EE->setGeometry(253, 158, 174, 42);
    EE->setStyleSheet(
        "background-color: #09ED12; color: black; font-size: 16px; "
        "font-family: Inter; font-weight: 500;"
    );

    VE = new QPushButton("Vietnamese - English", this);
    VE->setGeometry(454, 158, 174, 42);
    VE->setStyleSheet(
        "background-color: #119ECD; color: black; font-size: 16px; "
        "font-family: Inter; font-weight: 500;"
    );

    EV = new QPushButton("English - Vietnamese", this);
    EV->setGeometry(647, 158, 174, 42);
    EV->setStyleSheet(
        "background-color: #119ECD; color: black; font-size: 16px; "
        "font-family: Inter; font-weight: 500;"
    );

    slangs = new QPushButton("Slangs", this);
    slangs->setGeometry(844, 158, 174, 42);
    slangs->setStyleSheet(
        "background-color: #119ECD; color: black; font-size: 16px; "
        "font-family: Inter; font-weight: 500;"
    );

    emoji = new QPushButton("Emoji", this);
    emoji->setGeometry(1041, 158, 174, 42);
    emoji->setStyleSheet(
        "background-color: #119ECD; color: black; font-size: 16px; "
        "font-family: Inter; font-weight: 500;"
    );

    switchFromWordToDefintion = new QPushButton("Word - Definition", this);
    switchFromWordToDefintion->setGeometry(253, 222, 174, 42);
    switchFromWordToDefintion->setStyleSheet(
        "background-color: #09ED12; color: black; font-size: 16px; "
        "font-family: Inter; font-weight: 500;"
    );

    switchFromDefintionToWord = new QPushButton("Definition - Word", this);
    switchFromDefintionToWord->setGeometry(454, 222, 174, 42);
    switchFromDefintionToWord->setStyleSheet(
        "background-color: #119ECD; color: black; font-size: 16px; "
        "font-family: Inter; font-weight: 500;"
    );

    menuBar = new QFrame(this);
    menuBar->setGeometry(0, 50, 248, 670);
    menuBar->setStyleSheet("background-color: #CBBDBD;");
    menuBar->setFrameShape(QFrame::StyledPanel);
    menuBar->setFrameShadow(QFrame::Raised);

    favoriteListButton = new QPushButton("Your favourite list", this);
    favoriteListButton->setGeometry(0, 64, 248, 66);
    favoriteListButton->setStyleSheet(
        "background-color: #64CCC5; color: black; font-size: 20px; "
        "font-family: Inter; font-weight: 500;"
    );

    historyButton = new QPushButton("Searched history", this);
    historyButton->setGeometry(0, 143, 248, 66);
    historyButton->setStyleSheet(
        "background-color: #64CCC5; color: black; font-size: 20px; "
        "font-family: Inter; font-weight: 500;"
    );

    definitionQuizButton = new QPushButton("Definition quiz", this);
    definitionQuizButton->setGeometry(0, 222, 248, 66);
    definitionQuizButton->setStyleSheet(
        "background-color: #64CCC5; color: black; font-size: 20px; "
        "font-family: Inter; font-weight: 500;"
    );

    wordQuizButton = new QPushButton("Word quiz", this);
    wordQuizButton->setGeometry(0, 301, 248, 66);
    wordQuizButton->setStyleSheet(
        "background-color: #64CCC5; color: black; font-size: 20px; "
        "font-family: Inter; font-weight: 500;"
    );

    addNewWordButton = new QPushButton("Add a new word", this);
    addNewWordButton->setGeometry(0, 380, 248, 66);
    addNewWordButton->setStyleSheet(
        "background-color: #64CCC5; color: black; font-size: 20px; "
        "font-family: Inter; font-weight: 500;"
    );

    resetButton = new QPushButton("Set to original dictionary", this);
    resetButton->setGeometry(0, 459, 248, 66);
    resetButton->setStyleSheet(
        "background-color: #64CCC5; color: black; font-size: 20px; "
        "font-family: Inter; font-weight: 500;"
    );

    menuBar->hide();
    favoriteListButton->hide();
    historyButton->hide();
    wordQuizButton->hide();
    addNewWordButton->hide();
    definitionQuizButton->hide();
    resetButton->hide();

    QObject::connect(
        menuButton, &QPushButton::clicked, this, &MainWindow::toggleMenu
    );

    QObject::connect(
        searchBar, &QLineEdit::textChanged, this,
        &MainWindow::toggleCancelButton
    );

    QObject::connect(
        cancelButton, &QPushButton::clicked, this, &MainWindow::clearSearchBar
    );
}

MainWindow::~MainWindow() {
    delete headerBar;
    delete backgroundBelowHeaderBar;
    delete labelOnHeaderBar;
    delete searchBar;
    delete lookupButton;
    delete randomButton;
    delete menuButton;
    delete EE;
    delete EV;
    delete VE;
    delete slangs;
    delete emoji;

    delete favoriteListButton;
    delete menuBar;
    delete historyButton;
    delete wordQuizButton;
    delete addNewWordButton;
    delete definitionQuizButton;
    delete resetButton;
}

void MainWindow::toggleMenu() {
    if (!menuBar->isHidden()) {
        menuBar->hide();
        favoriteListButton->hide();
        historyButton->hide();
        wordQuizButton->hide();
        addNewWordButton->hide();
        definitionQuizButton->hide();
        resetButton->hide();
        menuButton->setIcon(QIcon("assets/Menu.png"));
    } else {
        menuBar->show();
        favoriteListButton->show();
        historyButton->show();
        wordQuizButton->show();
        addNewWordButton->show();
        definitionQuizButton->show();
        resetButton->show();
        menuButton->setIcon(QIcon("assets/cancelButton_Menu.png"));
    }
}

void MainWindow::toggleCancelButton() {
    if (!searchBar->text().isEmpty()) {
        randomButton->hide();
        cancelButton->show();
    } else {
        randomButton->show();
        cancelButton->hide();
    }
}

void MainWindow::clearSearchBar() { searchBar->clear(); }
