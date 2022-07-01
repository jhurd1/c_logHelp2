//
//  searchDirs.cpp
//  c_logHelp2
//
//  Created by Jamie  Hurd on 6/30/22.
//

#include "searchDirs.hpp"
#include "searchLogic.hpp"

struct dirent * contents;

//CONSTRUCTORS
SearchDirs::SearchDirs()
{

}

 SearchDirs::SearchDirs(std::string correspPath)
 {
  setcorrespPath(correspPath);
 }
 
 SearchDirs::SearchDirs(std::string correspPath, std::string stringToFind)
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
 
 /* **********************************
* DIRCONTENTS
* Take the search path
* Drill into subdirectories
* Call partner function, pushTheLines()
***************************************/
 void SearchDirs::dirContents(std::string correspPath, std::string stringToFind)
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
   SearchLogic sl;
   std::string stringInFile = sl.getstringInFile();
   s.pushTheLines(correspPath, stringToFind, stringInFile);
  }
 }
