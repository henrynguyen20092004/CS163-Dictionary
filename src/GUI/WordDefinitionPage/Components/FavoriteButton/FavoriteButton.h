#ifndef FAVORITE_BUTTON_H
#define FAVORITE_BUTTON_H

#include "../../../Components/Button/Button.h"

class FavoriteButton : public Button {
   private:
    bool inFavoriteList = false;
    const char *favoriteButtonOff = "assets/FavoriteButtonOff.png",
               *favoriteButtonOn = "assets/FavoriteButtonOn.png";

    void changeFavoriteState(const QString &word);

   public:
    void setWord(const QString &word);
    using Button::Button;
};

#endif
