//
//  replaceDatString.cpp
//  c_logHelp2
//
//  Created by Jamie  Hurd on 6/23/22.
//

#include "replaceDatString.hpp"
#include "searchLogic.hpp"
#include <stdio.h>

// should call searchLogic from here
// revise searchDriver too
void ReplaceDatString::overwriteContent()
{
  SearchLogic search;
  FILE *pFile;
  std::string correspPath = search.getcorrespPath();
  pFile = fopen(correspPath, "r+");//Get the file in question
}
