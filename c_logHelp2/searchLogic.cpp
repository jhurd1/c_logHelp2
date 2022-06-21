#include "searchLogic.hpp"
#include "search.hpp"
#include <sstream>

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

//Destructor
SearchLogic::~SearchLogic()
{
 in->close();
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
    // Create a new file.
    std::fstream out;
    out.open("new.txt", std::ios::out);
    if(!out)
    {
    std::cout << "Creating new output file failed.";
    abort();
    }
    std::cout << "file created.";
    out.close();
    
    // Search the existing file.
    std::fstream in;
    in.open(correspPath, std::ios::in);
    while(in >> stringInFile)
    {
        if(stringInFile == correspStrings)
        {
            std::ofstream write;
            write.open("new.txt");
            //write << in << std::endl;

        }
    }
    in.close();
    std::cin.ignore();
    std::cin.get();
 }
