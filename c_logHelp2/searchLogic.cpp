#include "searchLogic.hpp"
#include "search.hpp"
#include "replaceDatString.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

/* ***************************
* CONSTRUCTORS
*******************************/

// default
SearchLogic::SearchLogic()
{
    correspPath = "";
    correspStrings = "";
}

// non-default #1
SearchLogic::SearchLogic(std::string corresppath)
{
    setcorrespPath(correspPath);
}

// non-default #2
SearchLogic::SearchLogic(std::string correspPath, std::string correspStrings,
    std::string stringInFile)
{
    setcorrespPath(correspPath);
    setcorrespStrings(correspStrings);
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

std::string SearchLogic::getcorrespStrings() const
{
    return correspStrings;
}

std::string SearchLogic::getstringInFile() const
{
    return stringInFile;
}

void SearchLogic::setcorrespPath(std::string correspPath)
{
    this->correspPath = search.getPath();
}

void SearchLogic::setcorrespStrings(std::string correspStrings)
{
    this->correspStrings = search.getStrings();
}

void SearchLogic::setStringInFile(std::string stringInFile)
{
    this->stringInFile = stringInFile;
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
    while(in >> stringInFile)
    {
        if(stringInFile == correspStrings)
        {
          //getline(in, line);
          ReplaceDatString replaceDatString(stringInFile);
          stringInFile = replaceDatString.overwriteContent(stringInFile);
          std::ofstream file("new.txt");
          file << getline(in, stringInFile) << "\n" << std::endl;
          in.close();
        }
    }
 }
