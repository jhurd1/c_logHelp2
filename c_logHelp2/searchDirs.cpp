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
SearchDirs::SearchDirs(SearchLogic s) : s(s)
{
 
}

 SearchDirs::SearchDirs(std::string correspPath, SearchLogic s) : s(s)
 {
  setcorrespPath(correspPath);
 }
 
 SearchDirs::SearchDirs(std::string correspPath, std::string stringToFind, SearchLogic s) : s(s)
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
 
 /* **********************************
* DIRCONTENTS
* Take the search path
* Drill into subdirectories
* Call partner function, pushTheLines()
***************************************/
 void SearchDirs::dirContents(std::string correspPath, std::string stringToFind, std::vector<std::string> fileNames)
 {
  char* c_arr;
  c_arr = &correspPath[0];
  dirs = opendir(c_arr);
  if(!dirs)
  {
   std::cout << "failed to open dir";
   return;
  }
  while((contents = readdir(dirs))!=NULL)
  {
  for(auto itEntry = std::filesystem::recursive_directory_iterator(correspPath); itEntry != std::filesystem::recursive_directory_iterator(); ++itEntry) // recurse subdirectories once each
  {
   if(itEntry->is_directory()) // if it's a directory
   {
    std::filesystem::file_status stat;
    if(std::filesystem::exists(stat)) // if it's a file
    {
     
     
    }
   } else
   {
     
   }
   SearchLogic sl(correspPath);
   sl.pushTheLines(correspPath, stringToFind, stringInFile);
  }
  }
  closedir(dirs);
 }
