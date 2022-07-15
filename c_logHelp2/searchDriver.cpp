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
    //std::string stringToFind;
    int const words = 3;
    int const wordlength = 25;
    char array[words][wordlength];
    int i;
    int j;
   
 try {
 
    std::regex isnumber("^-?\\d+");
    std::regex ispath("/.*/+");
    std::smatch match;
    
    std::cout << "file path to search: ";
    std::cin >> correspPath;
    std::cout << std::endl;
     if(std::regex_match(correspPath, ispath))
     {
      std::cout << "You truly seek the holy grail." << "\n" << "Therefore, you may pass." << "\n" << std::endl;
     } else
     {
      std::cout << "\n" << "Not a path. You shall perish." << "\n" << "\n" << std::endl;
      return 1;
     }
    
    std::cout << "Enter up to three words, pressing enter between each. " << std::endl;
  for(int i = 0; i < words; i++)
  {
   for(int j = 0; j < wordlength; j++)
    {
      std::cin >> i;
      i++;
     if(std::regex_match(array[i], isnumber))
     {
      std::cout << "Inappropriate data type for input." << std::endl;
      return 1;
     }
    }
  }
      std::cout << array << std::endl;
      searchDirs.dirContents(correspPath, array[i][j]);
 } catch (std::exception &e) {
  std::cout << "searchDriver failed." << std::endl;
 }
    
   return 0;
}
