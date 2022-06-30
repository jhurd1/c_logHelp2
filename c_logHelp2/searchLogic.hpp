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
        std::string stringInFile;
        std::string replacement;
        std::string line;
        std::vector<std::string> tempStorage;
        Search search;

    public:
        void setcorrespPath(std::string correspPath);
        void setstringToFind(std::string stringToFind);
        void setStringInFile(std::string stringInFile);
        void setIn(std::ifstream in);
        void setLine(std::string line);
        
        std::string getcorrespPath() const;
        std::string getstringToFind() const;
        std::string getstringInFile() const;
        std::string getLine() const;
        
        SearchLogic();
        SearchLogic(std::string correspPath);
        SearchLogic(std::string correspPath, std::string stringToFind,
            std::string stringInFile);
        //~SearchLogic();
        void searchVec();
        void pushTheLines(std::string correspPath, std::string stringToFind,
            std::string stringInFile);
        void writeToFile();
};
#endif
