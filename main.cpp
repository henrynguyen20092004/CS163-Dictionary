#include "src/API/ResetDictionary/ResetDictionary.h"
#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char **argv) {
    Dictionary *test = GlobalVar::currentDictionary;
    std::vector<QString> x = {"hi", "bye"};
    test->addWordToDictionary("hello", x);
    return 0;
}
