#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char** argv) {
    srand(time(0));
    RandomList test = GlobalVar::currentDictionary->getFourRandomWords();
    return 0;
}
