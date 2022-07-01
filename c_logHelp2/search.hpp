#ifndef SEARCH_H
#define SEARCH_H
#include <string>

class Search
{
    private:
        // pointers improve efficiency
        // they prevent making copies in memory
        // by pointing the compiler to the
        // original memory block of the first instance
        std::string fpath;
        std::string searchStrings;

    public:
    
        void setPath(std::string fpath);
        void setStrings(std::string searchStrings);

        std::string getPath() const;
        std::string getStrings() const;
        
        Search();

        Search(std::string fpath);

        Search(std::string fpath, std::string searchStrings);

};


#endif
