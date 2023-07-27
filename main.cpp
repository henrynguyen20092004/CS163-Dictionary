#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char **argv) {
    Dictionary *test = &GlobalVar::data.DictVE;
    std::vector<QString> v = test->getKeywordFromSubKeyword("ăn");
    return 0;
}
