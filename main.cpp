#include "src/API/ResetDictionary/ResetDictionary.h"
#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char **argv) {
    Dictionary *test = GlobalVar::currentDictionary;
    std::vector<QString> x = {"hi", "bye"};
    test->editDefinitionsOfAWord("hydrogenize", x);
    std::vector<QString> result = test->getDefinition("hydrogenize");
    return 0;
}
