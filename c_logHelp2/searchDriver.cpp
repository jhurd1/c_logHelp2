#include <iostream>
#include <string>
#include "searchDirs.hpp"
#include <regex>

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
    std::regex isnumber("^-?\\d+");
    //std::regex ispath("^(?:[\\w]\\:|\\)(\\[a-z_\\-\\s0-9\\.]+)+\\.(txt|gif|pdf|doc|docx|xls|xlsx)$");
    std::regex ispath("^(?:[\\w]\\:|\\)(\\[a-z_\\-\\s0-9\\.]+)+\\");
    std::vector<std::string> temporary;
    std::smatch match;
    
    std::cout << "file path to search: ";
    while(std::getline(std::cin, correspPath))
    {
     if(std::regex_match(correspPath, ispath))
     {
      std::cin >> correspPath;
     }
    }
    
    std::cout << "Enter words to search, separated by a space: ";
    while(std::getline(std::cin, stringToFind))
    {
     if(std::regex_match(stringToFind, isnumber))
     {
      std::cout << "Inappropriate string type entry." << std::endl;
      return 1;
     } else
     {
      temporary.push_back(stringToFind);
     }
    }
    
 searchDirs.dirContents(correspPath, stringToFind);
    
   return 0;
}
