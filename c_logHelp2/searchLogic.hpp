#ifndef SEARCHLOGIC_H
#define SEARCHLOGIC_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "search.hpp"
#include <map>

class SearchLogic
{
    private:
        std::string correspPath;
        std::string stringToFind;
        std::string stringInFile;
        std::string replacement;
        std::string line;
        std::string newPath;
        std::vector<std::string> tempStorage;
        Search search;
        std::map<int, FILE>& fileMap;

    public:
        void setcorrespPath(std::string correspPath);
        void setstringToFind(std::string stringToFind);
        void setStringInFile(std::string stringInFile);
        void setIn(std::ifstream in);
        void setLine(std::string line);
        void setnewPath(std::string newPath);
        
        std::string getcorrespPath() const;
        std::string getstringToFind() const;
        std::string getstringInFile() const;
        std::string getLine() const;
        std::string getnewPath() const;
        
        SearchLogic(std::map<int,FILE> &fileMap);
        SearchLogic(std::string correspPath, std::map<int,FILE> &fileMap);
        SearchLogic(std::string correspPath, std::string stringToFind,
            std::string stringInFile, std::map<int,FILE> &fileMap);
        //~SearchLogic();
        void searchVec();
        void pushTheLines(std::string correspPath, std::string stringToFind,
            std::string stringInFile, std::map<int,FILE> &fileMap);
        void writeToFile();
};
#endif
