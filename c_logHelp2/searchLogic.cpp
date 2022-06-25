#include "searchLogic.hpp"
#include "search.hpp"
#include "replaceDatString.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

SearchLogic::SearchLogic()
{
    correspPath = "";
    correspStrings = "";
}

SearchLogic::SearchLogic(std::string corresppath)
{
    setcorrespPath(correspPath);
}

SearchLogic::SearchLogic(std::string correspPath, std::string correspStrings,
    std::string stringInFile)
{
    setcorrespPath(correspPath);
    setcorrespStrings(correspStrings);
    setStringInFile(stringInFile);
}

std::string SearchLogic::getcorrespPath() const
{
    return correspPath;
}

std::string SearchLogic::getcorrespStrings() const
{
    return correspStrings;
}

std::string SearchLogic::getStringInFile() const
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

 void SearchLogic::searchLogic(std::string correspPath, std::string correspStrings,
    std::string stringInFile)
 {
    std::fstream in;
    in.open(correspPath, std::ios::in);
    while(in.is_open())
    {
     in >> stringInFile;
        if(stringInFile == correspStrings)
        {
          ReplaceDatString replaceDatString;
          replaceDatString.overwriteContent(stringInFile);
          stringInFile = replaceDatString.getReplacement();
          std::ofstream file("new.txt");
          file << stringInFile << "\n" << std::endl;
          in.close();
        }
    }
 }
