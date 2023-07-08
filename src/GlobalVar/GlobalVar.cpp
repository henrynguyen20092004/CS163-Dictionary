#include "GlobalVar.h"

Data GlobalVar::data;
Dictionary *GlobalVar::currentDictionary = &GlobalVar::data.DictEE;
