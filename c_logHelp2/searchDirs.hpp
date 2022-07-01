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

class SearchDirs
{
 private:
   DIR *dirs;
   std::string correspPath;
   std::string stringToFind;
   
 public:
  SearchLogic s;
  
  SearchDirs();
  SearchDirs(std::string correspPath);
  SearchDirs(std::string correspPath, std::string stringToFind);
  
  void setcorrespPath(std::string correspPath);
  void setstringtoFind(std::string stringToFind);
  
  std::string getcorrespPath() const;
  std::string getstringtoFind() const;
  
  void dirContents(std::string correspPath, std::string stringToFind);
};

#endif /* searchDirs_hpp */
