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
        std::string *replacement;
        std::string line;
        std::string newPath;
        std::vector<std::string> tempStorage;
        std::vector<std::string> lineStorage;
        int word_number;
        Search search;

    public:
        void setcorrespPath(std::string correspPath);
        void setstringToFind(std::string stringToFind);
        void setStringInFile(std::string stringInFile);
        void setIn(std::ifstream in);
        void setLine(std::string line);
        void setnewPath(std::string newPath);
        void setword_number(int line_number);
        void setreplacement(std::string &replacement);
        
        std::string getcorrespPath() const;
        std::string getstringToFind() const;
        std::string getstringInFile() const;
        std::string getLine() const;
        std::string getnewPath() const;
        std::string getreplacement() const;
        int getword_number() const;
        
        SearchLogic();
        SearchLogic(std::string correspPath);
        SearchLogic(std::string correspPath, std::string stringToFind,
            std::string stringInFile, std::string &replacement);
        //~SearchLogic();
        bool convert(const std::string &line, std::string stringToFind, int word_number);
        void replaceString(std::string str, std::string stringToFind, std::string replacement);
        bool replacer(std::string& str, const std::string& stringToFind, const std::string& replacement);
        void searchVec(std::string stringToFind);
        void pushTheLines(std::string correspPath,
            std::string stringInFile, std::string stringToFind);
        void writeToFile();
};
#endif
