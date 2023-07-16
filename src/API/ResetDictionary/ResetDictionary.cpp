#include "ResetDictionary.h"

#include "../../GlobalVar/GlobalVar.h"

void resetCurrentDictionary() {
    GlobalVar::currentDictionary->resetDictionary();
}

void resetAllDictionaries() {
    GlobalVar::data.DictEE.resetDictionary();
    GlobalVar::data.DictEV.resetDictionary();
    GlobalVar::data.DictVE.resetDictionary();
    GlobalVar::data.DictSlang.resetDictionary();
    GlobalVar::data.DictEmoji.resetDictionary();
}
