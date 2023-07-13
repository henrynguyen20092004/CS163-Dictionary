#include "HashFunction.h"

int hashFunction(const QString& s, int tableSize) {
    int hash = 0, p = 29791, pow = 1;

    for (QChar c : s) {
        hash = (hash + (c.unicode()) * pow) % tableSize;
        pow = (pow * p) % tableSize;
    }

    return hash % tableSize;
}
