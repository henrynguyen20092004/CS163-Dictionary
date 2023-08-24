#include "FavoriteButton.h"

#include "../../../../GlobalVar/GlobalVar.h"

void FavoriteButton::changeFavoriteState(const QString& word) {
    KeyWithDictName keyWithDictName = {
        word, GlobalVar::currentDictionary->dictionaryName};
    setIcon(QIcon(inFavoriteList ? favoriteButtonOff : favoriteButtonOn));
    inFavoriteList ? GlobalVar::data.favoriteList.removeWord(keyWithDictName)
                   : GlobalVar::data.favoriteList.addWord(keyWithDictName);
    inFavoriteList = !inFavoriteList;
}

void FavoriteButton::setWord(const QString& word) {
    inFavoriteList = GlobalVar::data.favoriteList.contain(
        {word, GlobalVar::currentDictionary->dictionaryName}
    );
    setIcon(
        QIcon(inFavoriteList ? favoriteButtonOn : favoriteButtonOff)
    );
    disconnect();

    CONNECT(this, CLICKED, [=]() { changeFavoriteState(word); });
}
