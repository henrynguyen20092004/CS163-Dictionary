#include "Dict.h"

#include "../API/LoadData/LoadData.h"

HashTable Dict::EE = loadData(10007, "Data/OriginalEE.txt", "Data/NewEE.txt");
HashTable Dict::EV = loadData(5099, "Data/OriginalEV.txt", "Data/NewEV.txt");
HashTable Dict::VE = loadData(5309, "Data/OriginalVE.txt", "Data/NewVE.txt");
HashTable Dict::Slang =
    loadData(947, "Data/OriginalSlang.txt", "Data/NewSlang.txt");
HashTable Dict::Emoji =
    loadData(41, "Data/OriginalEmoji.txt", "Data/NewEmoji.txt");
