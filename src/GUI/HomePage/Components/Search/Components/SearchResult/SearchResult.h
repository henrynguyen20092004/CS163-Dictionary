#ifndef SEARCH_RESULT_H
#define SEARCH_RESULT_H

#include <vector>

#include "../../../../../Components/Button/Button.h"
#include "../../../../../Components/Frame/Frame.h"
#include "../../../../../Components/ScrollArea/ScrollArea.h"

class SearchResult : public QWidget {
    Q_OBJECT

   private:
    std::vector<Button*> resultButtons;
    QWidget* content;
    ScrollArea* scrollArea;
    int numberOfResults = 0;

    bool isWatching(QObject* watchingObject);
    bool eventFilter(QObject* watchingObject, QEvent* event) override;
    void showNoResult();

   public:
    SearchResult(QWidget* parent);
    ~SearchResult();
    void showResults(const std::vector<QString>& result);
    void hideResults();

   signals:
    void changeVisibility(bool visible);
    void resultClicked(const QString& result);
};

#endif
