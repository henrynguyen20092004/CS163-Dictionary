#ifndef HISTORY_H
#define HISTORY_H

#include <QFile>
#include <QString>
#include <QTextStream>
#include <vector>

class History {
   private:
    QString historyPath;
    int maxSize = 50;
    std::vector<QString> wordSet;
    bool loadData();
    bool saveData();
    int find(QString& key);

   public:
    History(QString& historyPath);
    bool add(QString& key);
    std::vector<QString> getHistory();
    ~History();
};

#endif
