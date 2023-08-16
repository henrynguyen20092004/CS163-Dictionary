#ifndef FAVORITE_WORD_H
#define FAVORITE_WORD_H

#include "../../../Components/Button/Button.h"

#define WORD_BUTTONS_PADDING_Y 30
#define DISTANCE 80

class FavoriteWord : public QWidget {
   private:
    Button *favoriteWordButton, *removeButton;

   public:
    FavoriteWord(QWidget *parent, const QString &word, int index);
    ~FavoriteWord();
    Button *getFavoriteWordButton();
};

#endif
