#ifndef HISTORY_H
#define HISTORY_H

#include "../Dictionary/KeyWithDictName/KeyWithDictName.h"

class History {
   private:
    std::string historyPath = "Data/History.txt";
    std::vector<KeyWithDictName> wordHistory;
    int maxSize = 50;

    void saveList();

   public:
    History();
    void add(const KeyWithDictName& data);
    std::vector<KeyWithDictName>* getHistory();
    void removeNonExistentWord(Dictionary* dictionary);
};

#endif
