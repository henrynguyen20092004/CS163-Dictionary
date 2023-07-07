#ifndef SWITCH_DICTIONARY_H
#define SWITCH_DICTIONARY_H

enum DictionaryName {
    EE,
    EV,
    VE,
    SLANG,
    EMOJI,
};

void switchDictionary(DictionaryName dictionaryName);

#endif
