#include "GetDictFromDictName.h"

#include "../../../GlobalVar/GlobalVar.h"

Dictionary *getDictFromDictName(DictionaryName dictionaryName) {
    switch (dictionaryName) {
        case EE:
            return &GlobalVar::data.DictEE;
        case VE:
            return &GlobalVar::data.DictVE;
        case EV:
            return &GlobalVar::data.DictEV;
        case SLANG:
            return &GlobalVar::data.DictSlang;
        case EMOJI:
            return &GlobalVar::data.DictEmoji;
    }
}
