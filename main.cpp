#include "src/GlobalVar/GlobalVar.h"
#include "src/API/SwitchDictionary/SwitchDictionary.h"

int main(int argc, char** argv) {
    Dictionary *test = GlobalVar::currentDictionary;
    switchDictionary(VE);
    Dictionary *test2 = GlobalVar::currentDictionary;
    return 0;
}
