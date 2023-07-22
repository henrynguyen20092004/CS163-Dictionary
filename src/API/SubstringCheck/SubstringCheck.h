#ifndef SUBSTRING_CHECK_H
#define SUBSTRING_CHECK_H

#include <QString>

#include "CharacterTable/CharacterTable.h"

bool substringCheck(
    const QString &str, const QString &subStr,
    const CharacterTable &characterTable
);

#endif
