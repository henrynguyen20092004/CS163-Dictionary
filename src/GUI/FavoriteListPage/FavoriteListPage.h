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

    void clear();

   public:
    FavoriteListPage();
    ~FavoriteListPage();
    void reload();

   signals:
    void favoriteWordClicked(const QString& word);
};

#endif
