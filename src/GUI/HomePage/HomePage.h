#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include "../Components/HeaderBar/HeaderBar.h"
#include "../Components/Image/Image.h"
#include "Components/Menu/Menu.h"
#include "Components/Search/Search.h"
#include "Components/SwitchDictionaryButton/SwitchDictionaryButton.h"
#include "Components/WordDefinitionButton/WordDefinitionButton.h"

class HomePage : public QWidget {
    Q_OBJECT

   private:
    Frame* background;
    HeaderBar* headerBar;
    Image* logo;
    SwitchDictionaryButton* switchDictionaryButton;
    WordDefinitionButton* wordDefinitionButton;
    Search* search;
    SearchResult* searchResult;
    Menu* menu;
    const char* mainStyle = "font-family: Inter; font-size: 20px;";

   private slots:
    void setAllButtonsDisabled(bool disabled);

   public:
    HomePage();
    ~HomePage();

   signals:
    void searchResultClicked(const QString& result);
    void wordQuizButtonClicked();
    void newWordButtonClicked();
};

#endif
