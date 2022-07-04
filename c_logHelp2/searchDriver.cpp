#include <iostream>
#include <string>

#include "searchDirs.hpp"
/* ****************************************
* SEARCHDRIVER
* The "main()" function that
* presses my objects into service.
*******************************************/
int main()
{
    SearchDirs searchDirs;
    std::string correspPath;
    std::string stringToFind;
    std::vector<std::string> fileNames;


    std::cout << "file path to search: ";
    std::cin >> correspPath;
    std::cout << "string to search: ";
    std::cin >> stringToFind;
    
 searchDirs.dirContents(correspPath, stringToFind, fileNames);
    
   return 0;
}
