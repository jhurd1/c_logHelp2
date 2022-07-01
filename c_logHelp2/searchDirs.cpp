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
 
 
 std::string returnFiles(std::string correspPath)
 {
  std::vector<std::string> fileNames;
  
  return correspPath;
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
     fileMap.insert(std::pair<int, FILE>()); // dump the file in the map
    }
   } else
   {
     // grab the files outside subdirectories
     // and put them in the map, too
     fileMap.insert(std::pair<int, FILE>());
   }
   SearchLogic sl;
   std::string stringInFile = sl.getstringInFile();
   for(auto const& j : fileMap)
   {
    fileNames.push_back({{j,correspPath}});
    // stackoverflow.com/questions/9138727/handling-map-of-files-in-c
    // You will need to extract the file by a dummy name to
    // send files one by one to pushTheLines().
    //s.pushTheLines(j.second, stringToFind, stringInFile);
   }
  }
  }
  closedir(dirs);
 }
