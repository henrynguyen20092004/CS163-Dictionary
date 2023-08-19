#include "FavoriteListPage.h"

#include "../../GlobalVar/GlobalVar.h"

FavoriteListPage::FavoriteListPage() : Page("FAVORITE LIST") {}

void FavoriteListPage::clear() {
    for (FavoriteWord* word : favoriteWords) {
        delete word;
    }

    favoriteWords.clear();
}

void FavoriteListPage::reload() {
    clear();

    for (FavoriteList::Node* cur = GlobalVar::data.favoriteList.getHead(); cur;
         cur = cur->next) {
        if (cur->data.dictionaryName ==
            GlobalVar::currentDictionary->dictionaryName) {
            favoriteWords.emplace_back(
                new FavoriteWord(content, cur->data.key, favoriteWords.size())
            );

            CONNECT(
                favoriteWords.back()->getFavoriteWordButton(), CLICKED, this,
                [=]() { emit favoriteWordClicked(cur->data.key); }
            );
        }
    }

    content->resize(
        content->width(),
        DISTANCE * favoriteWords.size() + WORD_BUTTONS_PADDING_Y
    );
}

FavoriteListPage::~FavoriteListPage() { clear(); }
