#include "StringUtil.h"

#include "CharUtil.h"

namespace utils {
   const std::string head(const std::string& word) {
      return word.substr(0, 1);
   }

   const std::string tail(const std::string& word) {
      if (word.length() == 0) return "";
      return word.substr(1);
   }

   const std::string zeroPad(const std::string& text, const unsigned int toLength) {
      auto zerosNeeded = toLength - text.length();
      return text + std::string(zerosNeeded, '0'); 
   }

   const std::string upperFront(const std::string& string) {
      return std::string(1, utils::upper(string.front()));
   }
}
