#include "Search.h"

Search::Search(QWidget *parent) {
    searchBar = new SearchBar(parent);
    searchResult = new SearchResult(parent);

    CONNECT(searchBar, &SearchBar::showResults, [=]() {
        searchResult->showResults(searchBar->search());
    });
    CONNECT(searchBar->getLineEdit(), &QLineEdit::textChanged, [=]() {
        searchResult->hideResults();
    });
}

SearchResult *Search::getSearchResult() { return searchResult; }

Search::~Search() {
    delete searchBar;
    delete searchResult;
}
