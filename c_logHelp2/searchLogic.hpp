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
        std::string *replacement;
        std::string line;
        Search search;
       std::string arr;

    public:
        void setcorrespPath(std::string correspPath);
        void setstringToFind(std::string stringToFind);
        
        void setIn(std::ifstream in);
        void setLine(std::string line);
        void setreplacement(std::string &replacement);
        
        std::string getcorrespPath() const;
        std::string getstringToFind() const;
        
        std::string getLine() const;
        std::string getreplacement() const;
        
        SearchLogic();
        SearchLogic(std::string correspPath);
        SearchLogic(std::string correspPath, std::string stringToFind,
           std::string &replacement);
   
        bool linehasthestring(const std::string &line, std::string stringToFind);
        void pushTheLines(std::string correspPath,
            std::array<std::string, 3> stringsToFind);
};
#endif
