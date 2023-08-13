#ifndef SEARCH_H
#define SEARCH_H

#include "SearchBar/SearchBar.h"
#include "SearchResult/SearchResult.h"

class Search {
   private:
    SearchBar* searchBar;
    SearchResult* searchResult;

   public:
    Search(QWidget* parent);
    ~Search();
    SearchResult* getSearchResult();
};

#endif
