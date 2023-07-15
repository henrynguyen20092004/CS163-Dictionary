#include "src/API/ResetDictionary/ResetDictionary.h"
#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char **argv) {
    Dictionary *test = GlobalVar::currentDictionary;
    test->removeWordFromDictionary("one", "Data/NewEE.txt");
    return 0;
}
