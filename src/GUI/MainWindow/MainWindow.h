#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "../Component/Image/Image.h"
#include "Component/HeaderBar/HeaderBar.h"
#include "Component/Menu/Menu.h"
#include "Component/SearchBar/SearchBar.h"
#include "Component/SwitchDictionaryButton/SwitchDictionaryButton.h"
#include "Component/WordDefinitionButton/WordDefinitionButton.h"

class MainWindow : public QMainWindow {
   private:
    Frame* background;
    HeaderBar* headerBar;
    Image* logo;
    SearchBar* searchBar;
    SwitchDictionaryButton* switchDictionaryButton;
    WordDefinitionButton* wordDefinitionButton;
    Menu* menu;

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
};

#endif
