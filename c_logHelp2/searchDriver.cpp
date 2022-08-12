#include <iostream>
#include <string>
#include "searchDirs.hpp"
#include <regex>
#include <array>

/* ****************************************
* SEARCHDRIVER
* The "main()" function that
* presses my objects into service.
*******************************************/
int main()
{
    SearchLogic SL;
    SearchDirs searchDirs;
    std::string word;
    std::string correspPath;
    std::array<std::string, 3> stringsToFind;
   
 try {
 
    std::regex isnumber("^-?\\d+");
    std::regex ispath("/.*/+");
    std::smatch match;
    
    std::cout << "file path to search ending with a '/': ";
    std::cin >> correspPath;
    std::cout << std::endl;
    
     if(std::regex_match(correspPath, ispath))
     {
      std::cout << "You truly seek the holy grail." << "\n" << "\n" << "You may pass." << "\n" << std::endl;
     } else
     {
      std::cout << "\n" << "Not a path." << "\n" << "You shall perish." << "\n" << "\n" << std::endl;
      return 1;
     }
    // Create an option for the user to select the quantity of search words
    // using a switch-case block. Then, prompt the user for the words.
    std::cout << "\n" << "Enter up to three words, pressing enter between each. " << std::endl;
    
  for(int i = 0; i < stringsToFind.size() && std::cin >> word; i++)
  {
      stringsToFind[i] = word;
     if(std::regex_match(word, isnumber))
     {
      std::cout << "Inappropriate data type for input." << std::endl;
      return 1;
     } else
     {
      searchDirs.dirContents(correspPath, word);
     }
  }
 } catch (std::exception &e)
 {
  std::cout << "searchDriver failed." << std::endl;
 }
    
   return 0;
}
