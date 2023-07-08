#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <vector>

class History {
   private:
    std::string historyPath = "Data/History.txt";
    int maxSize = 50;
    std::vector<QString> wordHistory;

    void saveData();

   public:
    History();
    void add(const QString& key);
    std::vector<QString> getHistory();
};

#endif
