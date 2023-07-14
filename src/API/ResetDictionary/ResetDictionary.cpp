#include "ResetDictionary.h"

#include <QFile>

#include "../../GlobalVar/GlobalVar.h"

void resetNewDictionary(const std::string &path) {
    QFile file(path.c_str());

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        throw std::runtime_error(path + " can't be loaded");
    }
}

void resetCurrentDictionary() {
    switch (GlobalVar::currentDictionary->dictionaryName) {
        case EE:
            resetNewDictionary("Data/NewEE.txt");
            break;

        case EV:
            resetNewDictionary("Data/NewEV.txt");
            break;

        case VE:
            resetNewDictionary("Data/NewVE.txt");
            break;

        case SLANG:
            resetNewDictionary("Data/NewSlang.txt");
            break;

        case EMOJI:
            resetNewDictionary("Data/NewEmoji.txt");
            break;
    }

    GlobalVar::currentDictionary->reloadDictionary();
}

void resetAllDictionaries() {
    resetNewDictionary("Data/NewEE.txt");
    resetNewDictionary("Data/NewEV.txt");
    resetNewDictionary("Data/NewVE.txt");
    resetNewDictionary("Data/NewSlang.txt");
    resetNewDictionary("Data/NewEmoji.txt");
    GlobalVar::data.DictEE.reloadDictionary();
    GlobalVar::data.DictEV.reloadDictionary();
    GlobalVar::data.DictVE.reloadDictionary();
    GlobalVar::data.DictSlang.reloadDictionary();
    GlobalVar::data.DictEmoji.reloadDictionary();
}
