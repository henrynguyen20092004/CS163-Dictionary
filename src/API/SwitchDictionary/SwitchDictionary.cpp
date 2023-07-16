#include "SwitchDictionary.h"

#include "../../GlobalVar/GlobalVar.h"

void switchDictionary(DictionaryName dictionaryName) {
    switch (dictionaryName) {
        case EE:
            GlobalVar::currentDictionary = &GlobalVar::data.DictEE;
            break;

        case EV:
            GlobalVar::currentDictionary = &GlobalVar::data.DictEV;
            break;

        case VE:
            GlobalVar::currentDictionary = &GlobalVar::data.DictVE;
            break;

        case SLANG:
            GlobalVar::currentDictionary = &GlobalVar::data.DictSlang;
            break;

        case EMOJI:
            GlobalVar::currentDictionary = &GlobalVar::data.DictEmoji;
            break;
    }
}
