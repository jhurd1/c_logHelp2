//
//  searchDirs.cpp
//  c_logHelp2
//
//  Created by Jamie  Hurd on 6/30/22.
//

#include "searchDirs.hpp"
#include "searchLogic.hpp"
#include <filesystem>

struct dirent * contents;

//CONSTRUCTORS
SearchDirs::SearchDirs()
{
 
}

 SearchDirs::SearchDirs(std::string correspPath, SearchLogic s) : s(s)
 {
  setcorrespPath(correspPath);
 }
 
 SearchDirs::SearchDirs(std::string correspPath, std::string stringToFind,
  SearchLogic s) : s(s)
 {
  setcorrespPath(correspPath);
  setstringtoFind(stringToFind);
 }
 
 /* *******************************
* ACCESSORS AND MUTATORS
* for encapsulation, of course!
*********************************/
 //MUTATORS
 void SearchDirs::setcorrespPath(std::string correspPath)
 {
  this->correspPath = s.getcorrespPath();
 }
 
 void SearchDirs::setstringtoFind(std::string stringToFind)
 {
  this->stringToFind = s.getstringToFind();
 }
 
 void SearchDirs::setstringInFile(std::string stringInFile)
 {
  this->stringInFile = s.getstringInFile();
 }
 
 void SearchDirs::setfilename(std::string filename)
 {
  this->filename = filename;
 }
 
 //ACCESSORS
 std::string SearchDirs::getcorrespPath() const
 {
  return s.getcorrespPath();
 }
 
 std::string SearchDirs::getstringtoFind() const
 {
  return stringToFind;
 }
 
 std::string SearchDirs::getstringInFile() const
 {
  return stringInFile;
 }
 
 std::string SearchDirs::getfilename() const
 {
  return filename;
 }
 
 void seeFiles(const char* filename)
 {
  
 }
 
 /* **********************************
* DIRCONTENTS
* Take the search path
* Drill into subdirectories
* Call partner function, pushTheLines()
***************************************/
 void SearchDirs::dirContents(std::string correspPath, std::string stringToFind)
 {
   for(auto const& entry : std::filesystem::recursive_directory_iterator(correspPath))
   {
     std::cout << entry.path() << std::endl;
     if(entry.path().extension().string() == ".txt")
     {
        std::string temppath;
        temppath = entry.path().string();
        std::cout << temppath;
        SearchLogic sl(temppath);
        sl.pushTheLines(temppath, stringInFile);
       }
      }
     }
    
