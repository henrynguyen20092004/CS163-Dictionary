#ifndef KEY_WITH_DICT_NAME_H
#define KEY_WITH_DICT_NAME_H

#include "../Dictionary.h"

struct KeyWithDictName {
    QString key = "";
    DictionaryName dictionaryName = EE;

    KeyWithDictName();
    KeyWithDictName(const QString& key, DictionaryName dictionaryName);
    bool operator==(const KeyWithDictName& other);
};

#endif
