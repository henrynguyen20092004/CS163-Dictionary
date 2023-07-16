#include "src/API/ResetDictionary/ResetDictionary.h"
#include "src/GUI/RandomWordWithFourDefinitons/RandomWordWithFourDefinitons.h"
#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    QApplication app(argc, argv);
    Dictionary* test = GlobalVar::currentDictionary;
    setupQuestion(test);
    return app.exec();
}
