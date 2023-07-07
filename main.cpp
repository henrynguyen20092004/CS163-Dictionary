#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char** argv) {
    FavoriteList test = GlobalVar::data.favoriteList;
    test.addWord("ngài");
    test.removeWord("hello");
    return 0;
}
