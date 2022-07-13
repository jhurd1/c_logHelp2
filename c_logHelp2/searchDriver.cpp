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
   
 try {
 
    std::regex isnumber("^-?\\d+");
    std::regex ispath("/.*/+");
    //std::regex ispath("/.*/.*/.*/");
    std::vector<std::string> temporary;
    std::smatch match;
    
    std::cout << "file path to search: ";
    std::cin >> correspPath;
     if(std::regex_match(correspPath, ispath))
     {
      std::cout << "You truly seek the holy grail. Therefore, you may pass.";
     } else
     {
      std::cout << "Not a path. You shall perish." << std::endl;
      return 1;
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
    searchDirs.dirContents(correspPath, stringToFind, temporary);
 } catch (std::exception &e) {
  std::cout << "searchDriver failed." << std::endl;
 }
    
   return 0;
}
