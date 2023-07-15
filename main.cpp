#include "src/API/ResetDictionary/ResetDictionary.h"
#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char **argv) {
    resetCurrentDictionary();
    Dictionary *test = GlobalVar::currentDictionary;
    std::vector<QString> a = test->getDefinition("a-");
    std::vector<QString> a1 = test->getDefinition("a cappella");
    std::vector<QString> a2 = test->getDefinition("a b c");

    return 0;
}
