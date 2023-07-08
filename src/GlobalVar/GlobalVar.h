#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include "../API/Data/Data.h"

struct GlobalVar {
    static Data data;
    static Dictionary *currentDictionary;
};

#endif
