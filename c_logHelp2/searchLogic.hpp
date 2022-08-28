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
    std::string* replacement;
    std::string outPath;
    std::string line;
    Search search;
    std::string arr;
    int* j;

public:
    // Mutators
    void setcorrespPath(std::string correspPath);
    void setstringToFind(std::string stringToFind);
    void setoutpath(std::string outPath);
    void setIn(std::ifstream in);
    void setLine(std::string line);
    void setreplacement(std::string& replacement);
    void setJ(int& j);

    // Accessors
    std::string getcorrespPath() const;
    std::string getstringToFind() const;
    std::string getoutpath() const;
    std::string getLine() const;
    std::string getreplacement() const;
    int getJ() const;

    // Constructors
    SearchLogic();
    SearchLogic(std::string correspPath);
    SearchLogic(std::string correspPath, std::string stringToFind,
        std::string& replacement);

    // Other Data Members
    int prompt(int &j);
    bool linehasthestring(const std::string& line, std::string stringToFind);
    void pushTheLines(std::string correspPath,
        std::string stringToFind);
};
#endif
