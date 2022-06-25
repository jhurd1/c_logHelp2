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
* their respective accessors and mutators.
***************************************************/
SearchLogic searchLogic;

std::string ReplaceDatString::getReplacement() const
{
 return replacement;
}

std::string ReplaceDatString::getstringInFile() const
{
 return searchLogic.getstringInFile();
}

void ReplaceDatString::setcorrespStrings(std::string correspStrings)
{
  this->correspStrings = searchLogic.getcorrespStrings();
}

void ReplaceDatString::setstringInFile(std::string stringInFile)
{
  //setting this to call overwrite() leads to empty string
  this->stringInFile = searchLogic.getstringInFile();
}

void ReplaceDatString::setReplacement(std::string replacement)
{
  this->replacement = replacement;
}

/*******************************************
* CONSTRUCTORS
************************************************/
  ReplaceDatString::ReplaceDatString()
  {
   //stringInFile = getstringInFile();
   //replacement = getReplacement();
  }
  
  ReplaceDatString::ReplaceDatString(std::string stringInFile)
  {
   setstringInFile(stringInFile);
  }
  
  ReplaceDatString::ReplaceDatString(std::string correspStrings, std::string stringInFile, std::string replacement)
  {
   setcorrespStrings(correspStrings);
   setstringInFile(stringInFile);
   setReplacement(replacement);
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
    replacement = " REDACTED ";
    stringInFile = replacement;
    return stringInFile;
   } else
   {
    breaker = false;
   }
  }
  return stringInFile;
}
