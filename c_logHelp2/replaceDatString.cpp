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

/* ***************************
* CONSTRUCTORS
*******************************/
  ReplaceDatString::ReplaceDatString()
  {
   
  }
  
  ReplaceDatString::ReplaceDatString(std::string &stringInFile) // value reaches this point
  {
   setstringInFile(stringInFile);
  }
  
  ReplaceDatString::ReplaceDatString(std::string stringInFile, std::string replacement)
  {
   setstringInFile(stringInFile);
   setReplacement(replacement);
  }


/* *******************************
* ACCESSORS AND MUTATORS
* for encapsulation, of course!
*********************************/
SearchLogic searchLogic;

void ReplaceDatString::setstringInFile(std::string stringInFile) // value is lost at this point
{
  //setting this to call overwrite() leads to empty string
  this->stringInFile = stringInFile;
}

void ReplaceDatString::setReplacement(std::string replacement)
{
  this->replacement = replacement;
}

std::string ReplaceDatString::getReplacement() const
{
 return replacement;
}

std::string ReplaceDatString::getstringInFile() const
{
 return searchLogic.getstringInFile();
}

/* ****************************************
* OVERWRITECONTENT
* Takes searchLogic's stringInFile value
* Compares it to IP and MAC regex
* Overwrites it if it compares
* Returns the original value, if not.
*******************************************/
std::string ReplaceDatString::overwriteContent(std::string stringInFile)
{
  bool breaker = true;
  std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
  std::regex m("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$");
  std::smatch match;
  while(breaker)
  {
   if((std::regex_match(stringInFile, r)) || (std::regex_match(stringInFile, m)))
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
