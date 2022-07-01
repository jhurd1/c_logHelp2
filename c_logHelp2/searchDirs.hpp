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
   std::string newPath;
   
 public:
  SearchLogic s;
  SearchDirs();
  SearchDirs(std::string correspPath);
  void setcorrespPath(std::string correspPath);
  void setnewPath(std::string newPath);
  std::string getnewPath();
  std::string getcorrespPath();
  void dirContents(std::string correspPath);
};


#endif /* searchDirs_hpp */
