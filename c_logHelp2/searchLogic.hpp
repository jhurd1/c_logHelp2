#ifndef SEARCHLOGIC_H
#define SEARCHLOGIC_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "search.hpp"

class SearchLogic
{
    private:
        std::string correspPath;
        std::string stringToFind;
        std::string *stringInFile;
        std::ifstream *in;
        std::vector<std::string> tempStorage;
        Search search;

    public:
        std::string getcorrespPath() const;
        std::string getstringToFind() const;
        std::string getstringInFile() const;
        void setcorrespPath(std::string correspPath);
        void setstringToFind(std::string stringToFind);
        void setStringInFile(std::string stringInFile);
        void setIn(std::ifstream in);
        SearchLogic();
        SearchLogic(std::string correspPath);
        SearchLogic(std::string correspPath, std::string stringToFind,
            std::string stringInFile);
        //~SearchLogic();
        std::string searchVec(std::string stringToFind, std::string stringInFile, std::vector<std::string> tempStorage);
        void searchLogic(std::string correspPath, std::string stringToFind,
            std::string &stringInFile);
        void writeToFile();
};
#endif
