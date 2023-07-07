#ifndef DATA_H
#define DATA_H

#include "../Dictionary/Dictionary.h"
#include "../FavoriteList/FavoriteList.h"

struct Data {
    Dictionary DictEE =
                   Dictionary(10007, "Data/OriginalEE.txt", "Data/NewEE.txt"),
               DictEV =
                   Dictionary(5099, "Data/OriginalEV.txt", "Data/NewEV.txt"),
               DictVE =
                   Dictionary(5309, "Data/OriginalVE.txt", "Data/NewVE.txt"),
               DictSlang = Dictionary(
                   947, "Data/OriginalSlang.txt", "Data/NewSlang.txt"
               ),
               DictEmoji = Dictionary(
                   41, "Data/OriginalEmoji.txt", "Data/NewEmoji.txt"
               );
    FavoriteList favoriteList;
};

#endif
