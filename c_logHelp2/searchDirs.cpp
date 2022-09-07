//
//  searchDirs.cpp
//  c_logHelp2
//
//  Created by Jamie  Hurd on 6/30/22.
//

#include "searchDirs.hpp"
#include "searchLogic.hpp"
#include <filesystem>
#include <array>

/* ***************************
* CONSTRUCTORS
*******************************/

/***************
* Default.
***************/
SearchDirs::SearchDirs()
{
 
}

/********************
* Non-default, one.
*********************/
 SearchDirs::SearchDirs(std::string correspPath, SearchLogic s) : s(s)
 {
  setcorrespPath(correspPath);
 }
 
 /*******************
* Non-default, two.
*********************/
 SearchDirs::SearchDirs(std::string correspPath, std::string stringToFind,
  SearchLogic s) : s(s)
 {
  setcorrespPath(correspPath);
  setstringtoFind(stringToFind);
 }
 
/* *******************************
* MUTATORS
*********************************/

/*******************
* setcorrespPath
********************/
 void SearchDirs::setcorrespPath(std::string correspPath)
 {
  this->correspPath = s.getcorrespPath();
 }
 
 /*******************
* setstringtofind
*********************/
 void SearchDirs::setstringtoFind(std::string stringToFind)
 {
  this->stringToFind = s.getstringToFind();
 }
 
/* *******************************
* ACCESSORS
*********************************/

/*****************
* getcorresppath
******************/
 std::string SearchDirs::getcorrespPath() const
 {
  return s.getcorrespPath();
 }
 
 /********************
* getstringtofind
*********************/
 std::string SearchDirs::getstringtoFind() const
 {
  return stringToFind;
 }
 
 /********************
* getstringinfile
**********************/
 std::string SearchDirs::getstringInFile() const
 {
  return stringInFile;
 }
 
 /* *******************************
* OTHER DATA MEMBERS
**********************************/

 /* **********************************
* DIRCONTENTS
* Take the search path
* Drill into subdirectories
* Call partner function, pushTheLines()
***************************************/
 void SearchDirs::dirContents(std::string correspPath, std::string stringToFind)
 {
  try
  {
   for(const auto &entry : std::filesystem::recursive_directory_iterator(correspPath))
   {
     std::cout << "\n" << "The file path this iteration is " << correspPath << " ." << std::endl;
     if((entry.path().extension().string() == ".txt") || (entry.path().extension().string() == ".log"))
     {
        std::string temppath;
        temppath = entry.path().string();
        SearchLogic sl(temppath);
        std::cout << "The temppath is " << temppath << std::endl;
        sl.pushTheLines(temppath, stringToFind);
       }
      }
  } catch (std::exception &e)
  {
   std::cout << "Recursive iteration failed from dirContents() in searchDirs" << std::endl;
  }
 }
    
