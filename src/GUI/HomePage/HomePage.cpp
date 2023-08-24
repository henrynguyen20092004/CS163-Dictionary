#include "HomePage.h"

HomePage::HomePage() : QWidget(nullptr) {
    setStyleSheet(mainStyle);

    background =
        new Frame(this, "background-color: #001C30;", {0, 0, 1280, 288});
    headerBar = new HeaderBar(this, "DICTIONARY");
    logo = new Image(this, "assets/UniLogo.png", {30, 88, 188, 150});
    switchDictionaryButton = new SwitchDictionaryButton(this);
    wordDefinitionButton = new WordDefinitionButton(this);
    search = new Search(this);
    menu = new Menu(this);
    successModal = new SuccessModal(this, "Word removed successfully!");
    searchResult = search->getSearchResult();

    installEventFilter(searchResult);
    CONNECT(
        searchResult, &SearchResult::changeVisibility, this,
        &HomePage::setAllButtonsDisabled
    );
    CONNECT(
        searchResult, &SearchResult::resultClicked, this,
        &HomePage::searchResultClicked
    );
    CONNECT(
        menu->getMenuButtons()[0], CLICKED, this,
        &HomePage::favoriteListButtonClicked
    );
    CONNECT(
        menu->getMenuButtons()[1], CLICKED, this,
        &HomePage::historyButtonClicked
    );
    CONNECT(
        menu->getMenuButtons()[2], CLICKED, this,
        &HomePage::wordQuizButtonClicked
    );
    CONNECT(
        menu->getMenuButtons()[3], CLICKED, this,
        &HomePage::definitionQuizButtonClicked
    );
    CONNECT(
        menu->getMenuButtons()[4], CLICKED, this,
        &HomePage::newWordButtonClicked
    );
}

void HomePage::setAllButtonsDisabled(bool disabled) {
    QList<QPushButton *> buttons = findChildren<QPushButton *>(),
                         searchResultButtons =
                             searchResult->findChildren<QPushButton *>();

    for (QPushButton *button : buttons) {
        if (!searchResultButtons.contains(button)) {
            button->setAttribute(Qt::WA_TransparentForMouseEvents, disabled);
        }
    }
}

void HomePage::removeWordSuccess() { successModal->show(); }

HomePage::~HomePage() {
    delete background;
    delete headerBar;
    delete logo;
    delete switchDictionaryButton;
    delete wordDefinitionButton;
    delete search;
    delete successModal;
    delete menu;
}
