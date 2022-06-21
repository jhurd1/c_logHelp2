#include "searchLogic.hpp"
#include "search.hpp"

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

SearchLogic::~SearchLogic()
{
 in.close();
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
    std::ifstream in(correspPath);
    //while(getline(in, correspStrings)&&(!in.eof()))
    while(in >> stringInFile)
    {
        if(stringInFile == correspStrings)
        {
            std::cout << "Found a match: " + stringInFile;
        } else if(!in.eof())
        {
            //std::cout << "I should keep searching, if my logic proves correct. ";
            std::cout << "The last word searched is: " + stringInFile << std::endl;
        } else
        {
         std::cout << "You must have reached the end of the file.";
        }
    }
    //in.close(); Do I need to call this again if the destructor does already?
    std::cin.ignore();
    std::cin.get();
    //std::exit();
 }
