#include <iostream>
#include <iomanip>
#include <string>
#include "search.hpp"

/* ********************
* CONSTRUCTORS
***********************/

//default
Search::Search()
{
    fpath = "";
    searchStrings = "";
}

// non-default #1
Search::Search(std::string fpath)
{
    setPath(fpath);
}

// non-default #2
Search::Search(std::string fpath, std::string searchStrings)
{
    setPath(fpath);
    setStrings(searchStrings);
}

/* *******************************
* ACCESSORS AND MUTATORS
* for encapsulation, of course!
*********************************/
void Search::setStrings(std::string searchStrings)
{
    this->searchStrings = searchStrings;
}

void Search::setPath(std::string fpath)
{
    this->fpath = fpath;
}

std::string Search::getStrings() const
{
    return searchStrings;
}

std::string Search::getPath() const
{
    return fpath;
}



