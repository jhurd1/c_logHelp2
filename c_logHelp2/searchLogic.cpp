#include "searchLogic.hpp"
#include "search.hpp"
#include "replaceDatString.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

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

std::string SearchLogic::getcorrespPath() const
{
    return correspPath;
}

std::string SearchLogic::getstringToFind() const
{
    return stringToFind;
}

std::string SearchLogic::getstringInFile() const
{
    return stringInFile;
}

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

/* **********************************
* SEARCHVEC
* Perform the search on the vector
* Make the call to overwrite the string.
***************************************/
std::string SearchLogic::searchVec(std::string stringInFile, std::vector<std::string> tempStorage)
{
  std::vector<std::string>::iterator i = find(tempStorage.begin(), tempStorage.end(), stringInFile);
  if(i != tempStorage.end())
  {
   ReplaceDatString replaceDatString(stringInFile);
   stringInFile = replaceDatString.overwriteContent(stringInFile);
  }
  return stringInFile;
}

/* **********************************
* SEARCHLOGIC
* Opens the input stream
* Takes action based on a conditional match
* Calls overwriteContent() to overwrite IPs
* and MAC addresses
* Writes results to a new file.
***************************************/
 void SearchLogic::searchLogic(std::string correspPath, std::string correspStrings,
    std::string stringInFile)
 {
    std::fstream in;
    in.open(correspPath, std::ios::in);
    std::string line;
    while(std::getline(in, line))
    {
          tempStorage.push_back(line);
          searchVec(stringToFind, tempStorage);
          std::ofstream file("new.txt");
          file << stringInFile << line << "\n" << std::endl;
          in.close();
    }
 }
