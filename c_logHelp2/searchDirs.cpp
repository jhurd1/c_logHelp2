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
 
 /*******CONSTRAST THIS TO GETCORRESPPATH ABOVE********/
 std::string SearchDirs::getstringtoFind() const
 {
  return stringToFind; /**Do we need to call
  s.getcorrespPath() or will the var alone do it?**/
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
 
 std::optional<std::string> StringFactory(bool oneOr, std::string correspPath)
  {
   if(oneOr)
   {
    return correspPath;
   }
   return {};
  }
 
 /* **********************************
* DIRCONTENTS
* Take the search path
* Drill into subdirectories
* Call partner function, pushTheLines()
***************************************/
 void SearchDirs::dirContents(std::string correspPath, std::string stringToFind)
 {
  /*char* c_arr;
  c_arr = &correspPath[0];
  dirs = opendir(c_arr);
  
  if(!dirs)
  {
   std::cout << "failed to open dir";
  }*/
   //for(contents = readdir(dirs); contents != NULL; contents = readdir(dirs))
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
    
