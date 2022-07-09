#include "searchLogic.hpp"
#include "search.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <cctype>
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
    std::string stringInFile, std::string &replacement)
{
    setcorrespPath(correspPath);
    setstringToFind(stringToFind);
    setStringInFile(stringInFile);
    setreplacement(replacement);
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
 
 void SearchLogic::setword_number(int word_number)
 {
  this->word_number = word_number;
 }
 
 void SearchLogic::setreplacement(std::string &replacement)
 {
  replacement = " REDACTED ";
  this->replacement = &replacement;
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
 
 int SearchLogic::getword_number() const
 {
  return word_number;
 }
 
 std::string SearchLogic::getreplacement() const
 {
  return *replacement;
 }
 
/* **********************************
* WANTED
* Return whether the search word
* exists in a line.
***************************************/
 bool wanted(const std::string &line, std::string stringToFind)
{
 return (line.find(stringToFind) != std::string::npos); // This shows the value of the overwritten word on the second iteration of the convert() loop.
}

/* **********************************
* LEN
* Currently, a non-static
* function belonging to no class.
* Measure the length of a string.
***************************************/
int len(std::string str)
{
 int length = 0;
 for (int i = 0; str[i] != '\0'; i++)
 {
  length++;
 }
 return length;
}

/* **********************************
* REPLACESTRING
* Calls len() and
* replaces the search word.
***************************************/
void SearchLogic::replaceString(std::string str, std::string stringToFind, std::string replacement)
{
 bool status = false;
 //replacement = "REDACTED";
 int startIndex = 0, endIndex = len(stringToFind);
 for(int i = 0; i < len(str); i++)
  {
  if(str[i] == stringToFind[0])
  {
   startIndex = i;
    for (int j = 0; j < len(stringToFind); j++, i++) {
				if (str[i] != stringToFind[j]) {
					status = false;
					break;
				}
				else
				{
					status = true;
				}
			}
            std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
            std::regex m("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$");
            std::smatch match;
			if (status && ((std::regex_match(stringToFind, r)) || (std::regex_match(stringToFind, m)))) {
				str.replace(startIndex, endIndex, replacement);
                std::cout << str;
                std::ofstream out("/Users/jamiehurd/desktop/c_logHelp2/c_logHelp2/new.txt", std::fstream::app);
                out << str; // it's the next line in the text file leading to a second overwrite here
                out.close();
				return;
			}
                
  }
  }
}

/* **********************************
* SEARCHVEC
* Perform the search on the vector
* Make the call to overwrite the string
* Write to the new file
***************************************/
void SearchLogic::searchVec(std::string stringToFind)
{
  for (auto line = lineStorage.begin(); line != lineStorage.end(); ++line) // we've already filtered line with wanted()
    {
      /*std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
      std::regex m("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$");
      std::smatch match;
      if((std::regex_match(stringToFind, r)) || (std::regex_match(stringToFind, m)))
       {*/
        std::string str = *line;
        *replacement = "REDACTED";
        replaceString(str, stringToFind, *replacement);
       }
      }
    // }

/* **********************************
* SEARCHLOGIC
* Opens the read stream
* Discern a line with a match
* Pass that line to a partner member to
* overwrite and output.
***************************************/
 void SearchLogic::pushTheLines(std::string correspPath,
    std::string stringInFile, std::string stringToFind)
 {
    std::fstream in;
    std::string line;
    std::string word;
  try
  {
     in.open(correspPath, std::ios::in);
     
     while(std::getline(in, line))
     {
     std::stringstream ss(line);
      if(wanted(line, stringToFind))
      {
       lineStorage.push_back(line);
      }
      }
     } catch (std::exception& e)
     {
      std::cout << "Error opening file." << std::endl;
     }
       in.close();
       searchVec(stringToFind);
    }
