#include <iostream>
#include <iomanip>
#include <string>
#include "search.hpp"

Search::Search()
{
    fpath = "";
    searchStrings = "";
}

Search::Search(std::string fpath)
{
    setPath(fpath);
}

Search::Search(std::string fpath, std::string searchStrings)
{
    setPath(fpath);
    setStrings(searchStrings);
}

void Search::setPath(std::string fpath)
{
    this->fpath = fpath;
}

std::string Search::getPath() const
{
    return fpath;
}

void Search::setStrings(std::string searchStrings)
{
    this->searchStrings = searchStrings;
}

std::string Search::getStrings() const
{
    return searchStrings;
}

