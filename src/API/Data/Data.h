#ifndef DATA_H
#define DATA_H

#include "../Dictionary/Dictionary.h"
#include "../FavoriteList/FavoriteList.h"
#include "../History/History.h"

struct Data {
    Dictionary
        DictEE = Dictionary(10007, "Data/OriginalEE.txt", "Data/NewEE.txt", EE),
        DictVE = Dictionary(5309, "Data/OriginalVE.txt", "Data/NewVE.txt", VE),
        DictEV = Dictionary(5099, "Data/OriginalEV.txt", "Data/NewEV.txt", EV),
        DictSlang = Dictionary(
            947, "Data/OriginalSlang.txt", "Data/NewSlang.txt", SLANG
        ),
        DictEmoji = Dictionary(
            41, "Data/OriginalEmoji.txt", "Data/NewEmoji.txt", EMOJI
        );
    FavoriteList favoriteList;
    History history;
};

#endif
