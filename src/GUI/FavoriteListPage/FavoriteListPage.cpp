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
            FavoriteWord* favoriteWord =
                new FavoriteWord(content, cur->data.key, favoriteWords.size());
            favoriteWords.push_back(favoriteWord);

            CONNECT(
                favoriteWord->getFavoriteWordButton(), CLICKED, this,
                [=]() { emit favoriteWordClicked(cur->data.key); }
            );
            CONNECT(favoriteWord->getRemoveButton(), CLICKED, this, [=]() {
                GlobalVar::data.favoriteList.removeWord(cur->data);

                std::vector<FavoriteWord*>::iterator it = std::find(
                    favoriteWords.begin(), favoriteWords.end(), favoriteWord
                );

                for (std::vector<FavoriteWord*>::iterator i = it + 1;
                     i != favoriteWords.end(); ++i) {
                    (*i)->move((*i)->x(), (*i)->y() - DISTANCE);
                }

                delete *it;
                favoriteWords.erase(it);
            });
        }
    }

    content->resize(
        content->width(),
        DISTANCE * favoriteWords.size() + WORD_BUTTONS_PADDING_Y
    );
}

FavoriteListPage::~FavoriteListPage() { clear(); }
