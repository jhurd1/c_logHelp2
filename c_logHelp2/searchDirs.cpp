//
//  searchDirs.cpp
//  c_logHelp2
//
//  Created by Jamie  Hurd on 6/30/22.
//

#include "searchDirs.hpp"
#include "searchLogic.hpp"

struct dirent * contents;

SearchDirs::SearchDirs()
{

}

 SearchDirs::SearchDirs(std::string correspPath)
 {
  setcorrespPath(correspPath);
 }
 
 void SearchDirs::setcorrespPath(std::string correspPath)
 {
  this->correspPath = s.getcorrespPath();
 }
 
 void SearchDirs::setnewPath(std::string newPath)
 {
 
 }
 
 std::string SearchDirs::getcorrespPath()
 {
  return s.getcorrespPath();
 }
 
 std::string SearchDirs::getnewPath()
 {
  return newPath;
 }
 
 void SearchDirs::dirContents(std::string correspPath)
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
   std::cout << "Which path (including the file name) would you like the output written to?" << "\n" << std::endl;
   std::cin >> newPath;
  }
 }
