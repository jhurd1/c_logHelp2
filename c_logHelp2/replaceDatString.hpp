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
  std::string stringInFile;
  std::string replacement;
  
 public:
  std::string getstringInFile() const;
  std::string getReplacement() const;
  void setstringInFile(std::string stringInFile);
  void setReplacement(std::string replacement);
  std::string overwriteContent(std::string stringInFile);
  ReplaceDatString();
  ReplaceDatString(std::string &stringInFile);
  ReplaceDatString(std::string stringInFile, std::string replacement);
};




#endif /* replaceDatString_hpp */
