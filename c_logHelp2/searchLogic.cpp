#include "searchLogic.hpp"
#include "search.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <sstream>
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
 
 void SearchLogic::setword_number(int word_number)
 {
  this->word_number = word_number;
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
 
 bool wanted(const std::string &line, std::string stringToFind)
{
 return (line.find(stringToFind) != std::string::npos);
}
 
 std::string convert(const std::string &line, std::string stringToFind, int word_number)
 {
    //while(wanted(line, stringToFind))
    //{
     size_t index = 0;
     std::string replacement(" REDACTED ");
     while((index = line.find(stringToFind, index)) != std::string::npos)
     {
      //line.replace(index, stringToFind.length(), replacement);
      stringToFind.replace(index, stringToFind.length(), replacement);
      index += replacement.length();
     }
     
     //stringToFind = replacement;
     return line;
     }
 //}

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
  //int i = 0;
  for (auto line = lineStorage.begin(); line != lineStorage.end(); ++line) // we've already filtered line with wanted()
    {
     //for (auto word = tempStorage.begin(); word != tempStorage.end(); ++word) //use cbegin() if you want it const
     //if(tempStorage[i] == stringToFind)
     if(wanted(*line, stringToFind))
     {
      std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
      std::regex m("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$");
      std::smatch match;
    
      if((std::regex_match(stringToFind, r)) || (std::regex_match(stringToFind, m)))
       {
        convert(*line, stringToFind, word_number);
        std::ofstream out("/Users/jamiehurd/desktop/c_logHelp2/c_logHelp2/new.txt");
        std::ostream_iterator<std::string> oi(out, "\n");
        //std::copy(tempStorage.begin(), tempStorage.end(), oi);
        std::copy(lineStorage.begin(), lineStorage.end(), oi); // This block is not outputting the line w/ the overwritten word
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
    std::string stringInFile, std::string stringToFind)
 {
    std::fstream in;
    std::string line, word;
    word_number = 0;
  try
  {
     in.open(correspPath, std::ios::in);
     /*while(in >> stringInFile)
     {
      tempStorage.push_back(stringInFile);
     }*/
     while(std::getline(in, line))
     {
      std::stringstream ss(line);
      ss >> word;
      word_number++;
      std::cout << "\n" << word_number << " " <<  word; // this is returning line number, not word number
      if(wanted(line, stringToFind) && (word == stringToFind)) // We are now capturing the entire line; ss >> line was treating "line" as a single word
      {
       lineStorage.push_back(line);
       //tempStorage.push_back(word);  // Okay, we are now pushing in the line containing a match thanks to bool wanted()
      }
      /*if(word == stringToFind)
      {
       //ss >> line;
       tempStorage.push_back(stringToFind);
      }*/
     }
     } catch (std::exception& e)
     {
      std::cout << "Error opening file." << std::endl;
     }
       searchVec(stringToFind);
       in.close();
    }
