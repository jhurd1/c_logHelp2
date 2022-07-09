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
 
 int countWords(const char* str)
{
   if (str == NULL)
      return 1;

   bool inSpaces = true;
   int numWords = 0;

   while (*str != '\0')
   {
      if (std::isspace(*str))
      {
         inSpaces = true;
      }
      else if (inSpaces)
      {
         numWords++;
         inSpaces = false;
      }

      ++str;
   }

   return numWords;
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
* CONVERT
* Replace the word in the line.
***************************************/
 /*std::string convert(const std::string &line, std::string stringToFind, int word_number)
 {
     //size_t index = 0;
     std::string replacement(" REDACTED ");
     while(wanted(line, stringToFind))
     {
     //https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
      stringToFind.replace(word_number, line.length(), replacement); // All values look correct.
      //stringToFind.replace(stringToFind.begin(), stringToFind.end(),stringToFind,replacement);
     }
     std::cout << "\n" << line;
     return line;
     }*/

bool SearchLogic::convert(std::string& str, const std::string& stringToFind, const std::string& replacement) {
    size_t start_pos = str.find(stringToFind);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, stringToFind.length(), getreplacement());
    std::cout << str;
    return true;
}

//std::string string("hello $name");
//replace(string, "$name", "Somename");

/* **********************************
* SEARCHVEC
* Perform the search on the vector
* Make the call to overwrite the string
* Write to the new file
***************************************/
void SearchLogic::searchVec(std::string stringToFind, int word_number)
{
  //std::string line;
  for (auto line = lineStorage.begin(); line != lineStorage.end(); ++line) // we've already filtered line with wanted()
    {
      std::regex r("\\b(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\b");
      std::regex m("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$");
      std::smatch match;
      if((std::regex_match(stringToFind, r)) || (std::regex_match(stringToFind, m)))
       {
        convert(*line, stringToFind, *replacement);
        std::cout << word_number << "\n";
        std::ofstream out("/Users/jamiehurd/desktop/c_logHelp2/c_logHelp2/new.txt");
        std::ostream_iterator<std::string> oi(out, "\n");
        std::copy(lineStorage.begin(), lineStorage.end(), oi); // This block is not outputting the line w/ the overwritten word
       }
      }
     }

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
    //word_number = 0;
  try
  {
     in.open(correspPath, std::ios::in);
     
     while(std::getline(in, line))
     {
      word_number = 0;
     std::stringstream ss(line); // This has to instantiate here for ss to work or open.
      while(ss >> word)
      {
        std::cout << word << " ";
        if(word != stringToFind)
        {
            ++word_number;
        } else
        {
          break;// Once you find the match, break out of the loop to stop the count.
        }
       }
       std::cout << word_number << std::endl;
       //word_number = 0;
      if(wanted(line, stringToFind))
      {
       std::cout << word_number << std::endl;
       lineStorage.push_back(line);
       searchVec(stringToFind, word_number);
      }
      }
     } catch (std::exception& e)
     {
      std::cout << "Error opening file." << std::endl;
     }
       in.close();
    }
