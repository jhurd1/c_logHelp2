#include "searchLogic.hpp"
#include "search.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <regex>
#include <cctype>
#include "searchDirs.hpp"

/* ***************************
* CONSTRUCTORS
*******************************/

/***************
* Default.
***************/
SearchLogic::SearchLogic()
{
    correspPath = "";
    stringToFind = "";
}

/********************
* Non-default, one.
*********************/
SearchLogic::SearchLogic(std::string corresppath)
{
    setcorrespPath(correspPath);
}

/*****************
* Non-default, one.
******************/
SearchLogic::SearchLogic(std::string correspPath, std::string stringToFind,
    std::string stringInFile, std::string &replacement)
{
    setcorrespPath(correspPath);
    setstringToFind(stringToFind);
    setStringInFile(stringInFile);
    setreplacement(replacement);
}

/* *******************************
* MUTATORS
*********************************/

/*****************
* setcorrespPath
******************/
void SearchLogic::setcorrespPath(std::string correspPath)
{
    this->correspPath = search.getPath();
}

/*****************
* setstringtofind
******************/
void SearchLogic::setstringToFind(std::string stringToFind)
{
    this->stringToFind = search.getStrings();
}

/*****************
* setstringinfile
******************/
void SearchLogic::setStringInFile(std::string stringInFile)
{
    this->stringInFile = stringInFile;
}

/*****************
* setline
******************/
void SearchLogic::setLine(std::string line)
{
 this->line = line;
}
 
 
/* *****************
* setreplacement
********************/
 void SearchLogic::setreplacement(std::string &replacement)
 {
  replacement = " REDACTED ";
  this->replacement = &replacement;
 }

/* *******************************
* ACCESSORS
**********************************/

/*****************
* getcorresppath
******************/
std::string SearchLogic::getcorrespPath() const
{
    return correspPath;
}

/*****************
* getstringtofind
******************/
std::string SearchLogic::getstringToFind() const
{
    return stringToFind;
}

/*****************
* getstringinfile
******************/
std::string SearchLogic::getstringInFile() const // the predecessor or caller is from replaceDatString
{
    return stringInFile;
}

/*****************
* getline
******************/
std::string SearchLogic::getLine() const
{
 return line;
}

/*****************
* getreplacement
******************/
 std::string SearchLogic::getreplacement() const
 {
  return *replacement;
 }
 
/* **********************************
* LINEHASTHESTRING
* Return whether the search word
* exists in a line.
***************************************/
 bool SearchLogic::linehasthestring(const std::string &line, std::string stringToFind)
{
 return (line.find(stringToFind) != std::string::npos);
}

/* *******************************
* OTHER DATA MEMBERS
**********************************/

/* **********************************
* SEARCHLOGIC
* Opens the read stream
* Discern a line with a match
* Overwrite as needed
* Output to a new file.
***************************************/
 void SearchLogic::pushTheLines(std::string correspPath,
    std::string stringInFile, std::string stringToFind, std::vector<std::string> temporary)
 {
    std::fstream in;
    std::string line;
    std::string word;
    std::string replacement = " REDACTED ";
  try
  {
     in.open(correspPath, std::ios::in);
     
     while(in)
     {
      std::getline(in, line);
      std::stringstream ss(line);
      
      if(linehasthestring(line, stringToFind))
      {
       while(ss >> word)
       {
       for(auto &word : temporary) // Line or word?
      {
        if(word.length() && word.back() == '.')
        {
         word.pop_back();
        }
         std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
         std::regex m("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$");
         std::smatch match;
          if(std::regex_match(word, r) || (std::regex_match(word, m))) // Checks if match on the same line exists to IP or MAC
          {
           auto iter = line.find(word);
           while(iter != std::string::npos)
           {
            size_t s = line.find(word);
            line.replace(s, word.length() + 1, replacement);
            iter = line.find(word, iter);
            std::ofstream out("/Users/jamiehurd/desktop/c_logHelp2/c_logHelp2/new.txt", std::fstream::app);
            out << line << std::endl;
            out.close();
          }
         }
        }
       }
      }
     }
    } catch (std::exception& e)
      {
       std::cout << "Error opening file." << std::endl;
      }
       in.close();
    }
