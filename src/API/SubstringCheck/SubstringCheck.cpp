#include "SubstringCheck.h"

bool substringCheck(
    const QString &str, const QString &subStr,
    const CharacterTable &characterTable
) {
    int strSize = str.size(), subStrSize = subStr.size();

    if (subStrSize > strSize) {
        return false;
    }

    for (int i = 0; i <= strSize - subStrSize;
         i += characterTable.find(str[i + subStrSize])) {
        int j = 0;

        for (; j < subStrSize; j++) {
            if (str[i + j] != subStr[j]) {
                break;
            }
        }

        if (j == subStrSize) {
            return true;
        }

        if (i == strSize - subStrSize) {
            return false;
        }
    }

    return false;
}
