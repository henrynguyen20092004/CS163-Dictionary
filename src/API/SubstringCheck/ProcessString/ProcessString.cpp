#include "ProcessString.h"

QString processString(const QString &oldString) {
    QString newString;

    for (QChar c: oldString) {
        if (c.isLetter()) {
            newString += c.toLower();
        } else if (c.isNumber() || c.isSpace()) {
            newString += c;
        }
    }

    return newString;
}
