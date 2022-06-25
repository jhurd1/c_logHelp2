#include <iostream>
#include <string>

#include "searchLogic.hpp"
#include "search.hpp"
/* ****************************************
* SEARCHDRIVER
* The "main()" function that
* presses my objects into service.
*******************************************/
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
    
    search.searchLogic(correspPath, correspStrings, stringInFile);
    
   return 0;
}
