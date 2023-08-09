#include "KeyWithDictName.h"

KeyWithDictName::KeyWithDictName() {}

KeyWithDictName::KeyWithDictName(
    const QString& key, DictionaryName dictionaryName
)
    : key(key), dictionaryName(dictionaryName) {}

bool KeyWithDictName::operator==(const KeyWithDictName& other) {
    return key == other.key && dictionaryName == other.dictionaryName;
}
