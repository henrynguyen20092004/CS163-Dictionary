#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char **argv) {
    srand(time(0));
    QString test1 = GlobalVar::currentDictionary->getRandomWord().first;
    QString test2 = GlobalVar::currentDictionary->getRandomWord().first;
    QString test3 = GlobalVar::currentDictionary->getRandomWord().first;
    QString test4 = GlobalVar::currentDictionary->getRandomWord().first;
    QString test5 = GlobalVar::currentDictionary->getRandomWord().first;
    return 0;
}
