#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char **argv) {
    Dictionary *test = GlobalVar::currentDictionary;
    std::vector<QString> v = test->getKeywordFromSubDefinition("you");
    return 0;
}
