//
//  replaceDatString.hpp
//  c_logHelp2
//
//  Created by Jamie  Hurd on 6/23/22.
//

#ifndef replaceDatString_hpp
#define replaceDatString_hpp
#include <stdio.h>
#include <string>

/**********************************************
* REPLACEDATSTRING
* A class designed to evaluate whether
* a found string embodies an IP or MAC
* address and to overwrite such strings.
**************************************************/
class ReplaceDatString
{
 private:
  FILE *pFile;
  std::string correspPath;
  std::string correspStrings;
  std::string stringInFile;
  std::string replacement;
  std::string getcorrespPath() const;
  std::string getcorrespStrings() const;
  std::string getstringInFile() const;
  std::string getReplacement() const;
  void setcorrespPath();
  void setcorrespStrings();
  void setstringInFile();
  void setReplacement();
  
  
 public:
  std::string overwriteContent();
  ReplaceDatString();
  ReplaceDatString(std::string correspStrings);
  ReplaceDatString(std::string correspStrings, std::string stringInFile, std::string replacement);
};




#endif /* replaceDatString_hpp */
