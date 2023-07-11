#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char **argv) {
    Dictionary *test = GlobalVar::currentDictionary;
    std::vector<QString> b = test->getDefinition("xin chào");
    return 0;
}
