#include "Dictionary.h"

#include "../API/LoadData/LoadData.h"

HashTable Dictionary::EE = loadData(10007, "Data/OriginalEE.txt", "Data/NewEE.txt");
HashTable Dictionary::EV = loadData(5099, "Data/OriginalEV.txt", "Data/NewEV.txt");
HashTable Dictionary::VE = loadData(5309, "Data/OriginalVE.txt", "Data/NewVE.txt");
HashTable Dictionary::Slang =
    loadData(947, "Data/OriginalSlang.txt", "Data/NewSlang.txt");
HashTable Dictionary::Emoji =
    loadData(41, "Data/OriginalEmoji.txt", "Data/NewEmoji.txt");
