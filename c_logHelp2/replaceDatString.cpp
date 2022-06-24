//
//  replaceDatString.cpp
//  c_logHelp2
//
//  Created by Jamie  Hurd on 6/23/22.
//

#include "replaceDatString.hpp"
#include "searchLogic.hpp"
#include <stdio.h>

// should call searchLogic from here
// revise searchDriver too
void ReplaceDatString::overwriteContent()
{
  SearchLogic search;
  std::string correspPath = search.getcorrespPath();
  std::string correspStrings = search.getcorrespStrings();
  std::string stringInFile = search.getStringInFile();
  std::string replacement = " **** ";
  std::string line;
  size_t len = stringInFile.length();
  std::string regularExpression = R"\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\b";
  
  do
  {
   search.searchLogic(correspPath, correspStrings, stringInFile);
   
  }
  while(true);
  
  
}
