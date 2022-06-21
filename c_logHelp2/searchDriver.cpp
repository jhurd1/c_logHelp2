#include <iostream>
#include <string>

#include "searchLogic.hpp"
#include "search.h"

/****************************************************************
 * Function: main
 * Purpose: Drive the machinery for the search
 ****************************************************************/
int main()
{
    SearchLogic search;
    std::string correspPath;
    std::string correspStrings;
    std::string stringInFile;


    std::cout << "file path to search: ";
    std::cin >> correspPath;
    std::cout << "string to search: ";
    std::cin >> correspStrings;

    std::cout << "Your path: " + correspPath + " , " + "and your search string: " + correspStrings;

    search.searchLogic(correspPath, correspStrings, stringInFile);

   return 0;
}
