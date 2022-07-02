//
//  searchDirs.hpp
//  c_logHelp2
//
//  Created by Jamie  Hurd on 6/30/22.
//

#ifndef searchDirs_hpp
#define searchDirs_hpp

#include <stdio.h>
#include <dirent.h>
#include <string>
#include "searchLogic.hpp"
#include <map>

class SearchDirs
{
 private:
   DIR *dirs;
   std::string correspPath;
   std::string stringToFind;
   std::map<int, FILE>* fileMap;
   std::vector<std::string> fileNames;
   std::string stringInFile;
   
 public:
  SearchLogic s;
  
  SearchDirs(SearchLogic s);
  SearchDirs(std::string correspPath, SearchLogic s);
  SearchDirs(std::string correspPath, std::string stringToFind, SearchLogic s);
  
  void setcorrespPath(std::string correspPath);
  void setstringtoFind(std::string stringToFind);
  void setstringInFile(std::string stringInFile);
  
  std::string getcorrespPath() const;
  std::string getstringtoFind() const;
  std::string getstringInFile() const;
  
  std::string returnFiles();
  void dirContents(std::string correspPath, std::string stringToFind, std::vector<std::string> fileNames);
};

#endif /* searchDirs_hpp */
