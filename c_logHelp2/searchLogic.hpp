#ifndef SEARCHLOGIC_H
#define SEARCHLOGIC_H
#include <string>
#include <iostream>
#include <fstream>
#include "search.hpp"

class SearchLogic
{
    private:
        std::string correspPath;
        std::string correspStrings;
        std::string stringInFile;
        std::ifstream in;
        Search search;

    public:
        std::string getcorrespPath() const;
        std::string getcorrespStrings() const;
        std::string getStringInFile() const;
        void setcorrespPath(std::string correspPath);
        void setcorrespStrings(std::string correspStrings);
        void setStringInFile(std::string stringInFile);
        void setIn(std::ifstream in);
        SearchLogic();
        SearchLogic(std::string correspPath);
        SearchLogic(std::string correspPath, std::string correspStrings,
            std::string stringInFile);
        ~SearchLogic();
        void searchLogic(std::string correspPath, std::string correspStrings,
            std::string stringInFile);
};
#endif
