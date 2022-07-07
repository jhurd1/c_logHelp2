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

void SearchLogic::setnewPath(std::string newPath)
 {
 
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
    return stringInFile;
}

std::string SearchLogic::getLine() const
{
 return line;
}

std::string SearchLogic::getnewPath() const
 {
  return newPath;
 }
 
 bool wanted(const std::string &line, std::string stringToFind)
 {
  return (line.find(stringToFind) != std::string::npos);
 }

/* **********************************
* SEARCHVEC
* Perform the search on the vector
* Make the call to overwrite the string
* Write to the new file
***************************************/
void SearchLogic::searchVec(std::string stringToFind)
{
  //int index = 1;
  std::string line;
  int i = 0;
  for (auto line = lineStorage.begin(); line != lineStorage.end(); ++line)
    {
     for (auto word = tempStorage.begin(); word != tempStorage.end(); ++word) //use cbegin() if you want it const
     if(tempStorage[i] == stringToFind)
     {
      std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
      std::regex m("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$");
      std::smatch match;
    
      if((std::regex_match(tempStorage[i], r)) || (std::regex_match(tempStorage[i], m)))
       {
        
        replacement = " REDACTED ";
        tempStorage[i] = replacement;
        
         {
          if (line->find(*word) != std::string::npos)
          {
           std::ofstream out("/new.txt");
           std::ostream_iterator<std::string> oi(out, "\n");
           std::copy(tempStorage.begin(), tempStorage.end(), oi);
           std::copy(lineStorage.begin(), lineStorage.end(), oi);
         }
        }
      }
     }
    }
   }

/* **********************************
* SEARCHLOGIC
* Opens the read stream
* Calls overwriteContent() to overwrite IPs
* and MAC addresses
***************************************/
 void SearchLogic::pushTheLines(std::string correspPath,
    std::string stringInFile)
 {
    std::fstream in;
    std::string line;
  try
  {
     in.open(correspPath, std::ios::in);
     while(in >> stringInFile)
     {
      tempStorage.push_back(stringInFile);
     }
     while(std::getline(in, line)) // The program does not enter this block.
     {
      if(wanted(line, stringToFind))
      {
       lineStorage.push_back(line);
      }
     }
     } catch (std::exception& e)
     {
      std::cout << "Error opening file." << std::endl;
     }
       searchVec(stringToFind);
       in.close();
    }
