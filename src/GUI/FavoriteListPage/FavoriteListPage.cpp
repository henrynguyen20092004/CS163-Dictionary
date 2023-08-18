#include "FavoriteListPage.h"

#include "../../API/Dictionary/GetDictFromDictName/GetDictFromDictName.h"
#include "../../GlobalVar/GlobalVar.h"

FavoriteListPage::FavoriteListPage() : Page("FAVOURITE LIST") {
    int index = 0;

    for (FavoriteList::Node* cur = GlobalVar::data.favoriteList.getHead(); cur;
         cur = cur->next) {
        FavoriteWord* currentWord =
            new FavoriteWord(content, cur->data.key, index++);

        CONNECT(currentWord->getFavoriteWordButton(), CLICKED, this, [=]() {
            emit favoriteWordClicked(
                cur->data.key, getDictFromDictName(cur->data.dictionaryName)
            );
        });

        favoriteWords.push_back(currentWord);
    }

    content->resize(
        content->width(), DISTANCE * index + WORD_BUTTONS_PADDING_Y
    );
}

FavoriteListPage::~FavoriteListPage() {
    for (FavoriteWord* word : favoriteWords) {
        delete word;
    }
}
