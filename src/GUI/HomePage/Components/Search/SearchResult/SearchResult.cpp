#include "SearchResult.h"

#define RESULT_HEIGHT 60
#define MAX_RENDER_RESULT 7
#define MAX_RESULT 42

#include <QEvent>

SearchResult::SearchResult(QWidget* parent) : QWidget(parent) {
    setGeometry(256, 140, 972, 0);
    hide();

    content = new QWidget(this);
    scrollArea = new ScrollArea(this, content, width(), 0);

    content->setGeometry(0, 0, width() - 20, 0);
    scrollArea->setStyleSheet(
        "background-color: #296ACC; font-weight: 500;"
    );

    for (int i = 0; i < MAX_RESULT; ++i) {
        resultButtons.push_back(new Button(
            content, "text-align: left; border: none; padding-left: 16px;", "",
            {0, RESULT_HEIGHT * i, width() - 20, RESULT_HEIGHT}
        ));
    }
}

bool SearchResult::isWatching(QObject* watchingObject) {
    for (int i = 0; i < MAX_RESULT; ++i) {
        if (resultButtons[i] == watchingObject) {
            return true;
        }
    }

    return watchingObject == this || watchingObject == content ||
           watchingObject == scrollArea;
}

bool SearchResult::eventFilter(QObject* watchingObject, QEvent* event) {
    if (isVisible() && event->type() == QEvent::MouseButtonPress &&
        !isWatching(watchingObject)) {
        hideResults();
        return true;
    }

    return QObject::eventFilter(watchingObject, event);
}

void SearchResult::showNoResult() {
    resultButtons[0]->disconnect();
    resultButtons[0]->setText("NO WORD FOUND!");
    resize(width(), RESULT_HEIGHT);
    scrollArea->resize(width(), height());
    content->resize(width() - 20, RESULT_HEIGHT);
    show();
    emit changeVisibility(isVisible());
}

void SearchResult::showResults(const std::vector<QString>& result) {
    int n = result.size();

    if (n == 0) {
        showNoResult();
        return;
    }

    int showResult = std::min(n, MAX_RESULT);

    for (int i = 0; i < showResult; ++i) {
        resultButtons[i]->disconnect();
        resultButtons[i]->setText(result[i]);

        CONNECT(resultButtons[i], CLICKED, [=]() {
            hideResults();
            emit resultClicked(result[i]);
        });
    }

    if (showResult > MAX_RENDER_RESULT) {
        resize(width(), RESULT_HEIGHT * MAX_RENDER_RESULT + 20);
    } else {
        resize(width(), RESULT_HEIGHT * showResult);
    }

    scrollArea->resize(width(), height());
    content->resize(width() - 20, RESULT_HEIGHT * showResult);

    show();
    emit changeVisibility(isVisible());
}

void SearchResult::hideResults() {
    hide();
    emit changeVisibility(isVisible());
}

SearchResult::~SearchResult() {
    for (Button* button : resultButtons) {
        delete button;
    }

    delete content;
    delete scrollArea;
}
