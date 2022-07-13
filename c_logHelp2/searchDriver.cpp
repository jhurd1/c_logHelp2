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
    std::string stop;
    std::string correspPath;
    std::string stringToFind;
   
 try {
 
    std::regex isnumber("^-?\\d+");
    std::regex ispath("/.*/+");
    std::vector<std::string> temporary;
    std::smatch match;
    
    std::cout << "file path to search: ";
    std::cin >> correspPath;
     if(std::regex_match(correspPath, ispath))
     {
      std::cout << "You truly seek the holy grail. Therefore, you may pass." << std::endl;
     } else
     {
      std::cout << "Not a path. You shall perish." << std::endl;
      return 1;
     }
    
    std::cout << "Enter up to three words, pressing enter between each. Enter '.' when through. " << std::endl;
    while(std::getline(std::cin, stringToFind) && stop != ".")
    {
     if(std::regex_match(stringToFind, isnumber))
     {
      std::cout << "Inappropriate data type for input." << std::endl;
      return 1;
     } else
     {
      std::cin >> stringToFind;
      temporary.push_back(stringToFind);
     }
    }
    searchDirs.dirContents(correspPath, stringToFind, temporary);
 } catch (std::exception &e) {
  std::cout << "searchDriver failed." << std::endl;
 }
    
   return 0;
}
