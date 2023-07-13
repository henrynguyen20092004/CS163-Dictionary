#include "src/API/SwitchDictionary/SwitchDictionary.h"
#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char **argv) {
    switchDictionary(VE);
    Dictionary *test = GlobalVar::currentDictionary;
    std::vector<QString> b = test->getDefinition("chào");
    return 0;
}
