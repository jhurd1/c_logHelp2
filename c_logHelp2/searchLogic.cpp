#include "searchLogic.hpp"
#include "search.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include "searchDirs.hpp"

/* ***************************
* CONSTRUCTORS
*******************************/

// default
SearchLogic::SearchLogic()
{
    correspPath = "";
    stringToFind = "";
}

// non-default #1
SearchLogic::SearchLogic(std::string corresppath)
{
    setcorrespPath(correspPath);
}

// non-default #2
SearchLogic::SearchLogic(std::string correspPath, std::string stringToFind,
    std::string stringInFile)
{
    setcorrespPath(correspPath);
    setstringToFind(stringToFind);
    setStringInFile(stringInFile);
}

/* *******************************
* ACCESSORS AND MUTATORS
* for encapsulation, of course!
*********************************/
void SearchLogic::setcorrespPath(std::string correspPath)
{
    this->correspPath = search.getPath();
}

void SearchLogic::setstringToFind(std::string stringToFind)
{
    this->stringToFind = search.getStrings();
}

void SearchLogic::setStringInFile(std::string stringInFile)
{
    this->stringInFile = stringInFile;
}

void SearchLogic::setLine(std::string line)
{
 this->line = line;
}

std::string SearchLogic::getcorrespPath() const
{
    return correspPath;
}

std::string SearchLogic::getstringToFind() const
{
    return stringToFind;
}

std::string SearchLogic::getstringInFile() const // the predecessor or caller is from replaceDatString
{
    return stringInFile; // bad access because it's NULL
}

std::string SearchLogic::getLine() const
{
 return line;
}

/* **********************************
* SEARCHVEC
* Perform the search on the vector
* Make the call to overwrite the string.
***************************************/
void SearchLogic::searchVec()
{
  int index = 1;
  while(index < tempStorage.size())
  {
    for(unsigned int i = 0; i < tempStorage.size(); i++)
    {
     index += 1;
     if(tempStorage[i].compare(stringToFind))
     {
      std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
      std::regex m("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$");
      std::smatch match;
    
      if((std::regex_match(tempStorage[i], r)) || (std::regex_match(tempStorage[i], m)))
    {
     replacement = " REDACTED ";
     tempStorage[i] = replacement;
    }
      index += 1;
      SearchDirs d;
      d.dirContents(correspPath);
      std::string newPath = d.getnewPath();
      std::ofstream out(newPath);
      std::ostream_iterator<std::string> oi(out, "\n");
      std::copy(tempStorage.begin(), tempStorage.end(), oi);
     }
    }
   }
  }

/* **********************************
* SEARCHLOGIC
* Opens the input stream
* Takes action based on a conditional match
* Calls overwriteContent() to overwrite IPs
* and MAC addresses
* Writes results to a new file.
***************************************/
 void SearchLogic::pushTheLines(std::string correspPath, std::string stringToFind,
    std::string stringInFile)
 {
    std::fstream in;
    in.open(correspPath, std::ios::in);
    while(in >> stringInFile)
    {
      tempStorage.push_back(stringInFile);
    }
    while(in.is_open())
    {
      searchVec();
      in.close();
    }
 }
