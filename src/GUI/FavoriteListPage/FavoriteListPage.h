#ifndef FAVORITE_LIST_PAGE_H
#define FAVORITE_LIST_PAGE_H

#include <vector>

#include "../../API/Dictionary/Dictionary.h"
#include "../Page/Page.h"
#include "Components/FavoriteWord/FavoriteWord.h"

class FavoriteListPage : public Page {
    Q_OBJECT

   private:
    std::vector<FavoriteWord*> favoriteWords;

   public:
    FavoriteListPage();
    ~FavoriteListPage();

   signals:
    void favoriteWordClicked(const QString& word, Dictionary* dictionary);
};

#endif
