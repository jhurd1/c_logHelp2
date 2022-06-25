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

std::string ReplaceDatString::getReplacement() const
{
 return replacement;
}

std::string ReplaceDatString::getstringInFile() const
{
 return stringInFile;
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

/*******************************************
* CONSTRUCTORS
************************************************/
  ReplaceDatString::ReplaceDatString()
  {
   correspStrings = "";
   stringInFile = "";
   setReplacement();
  }
  
  ReplaceDatString::ReplaceDatString(std::string stringInFile)
  {
   setstringInFile();
  }
  ReplaceDatString::ReplaceDatString(std::string correspStrings, std::string stringInFile, std::string replacement)
  {
   setcorrespStrings();
   setstringInFile();
   setReplacement();
  }


/****************************************
FUNCTIONS and LOGIC
 ****************************************/
std::string ReplaceDatString::overwriteContent(std::string stringInFile)
{
  bool breaker = true;
  std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
  std::smatch match;
  // the while loop is used because it runs at least once
  while(breaker)
  {
   if(std::regex_match(stringInFile, r))
   {
    stringInFile = replacement;
    return stringInFile;
   }
  }
  return stringInFile;
}
