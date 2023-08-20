#ifndef SEARCH_H
#define SEARCH_H

#include "Components/SearchBar/SearchBar.h"
#include "Components/SearchResult/SearchResult.h"

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
