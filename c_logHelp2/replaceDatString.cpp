//
//  replaceDatString.cpp
//  c_logHelp2
//
//  Created by Jamie  Hurd on 6/23/22.
//

#include "replaceDatString.hpp"
#include "searchLogic.hpp"
#include <stdio.h>
#include <regex>

/*************************************************
* DATA MEMBERS and
* their respective mutators.
***************************************************/
SearchLogic searchLogic;

std::string ReplaceDatString::getcorrespPath() const
{
   return correspPath;
}

std::string ReplaceDatString::getReplacement() const
{
 return replacement;
}

void ReplaceDatString::setcorrespPath()
{
  this->correspPath = searchLogic.getcorrespPath();
}

void ReplaceDatString::setcorrespStrings()
{
  this->correspStrings = searchLogic.getcorrespStrings();
}

void ReplaceDatString::setstringInFile()
{
  this->stringInFile = searchLogic.getStringInFile();
}

void ReplaceDatString::setReplacement()
{
  this->replacement = " ******* ";
}

/****************************************
FUNCTIONS and LOGIC
 ****************************************/
std::string ReplaceDatString::overwriteContent()
{
  std::string line;
  size_t len = stringInFile.length();
  std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
  
  
  return stringInFile;
  
}
