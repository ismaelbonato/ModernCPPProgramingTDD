#include "CharUtil.h"

#include <string>

namespace utils {
   const bool isVowel(const char letter) {
      return std::string("aeiouy").find(std::tolower(letter)) != std::string::npos;
   }

   const char upper(const char c) {
      return std::toupper(static_cast<unsigned char>(c));
   }

   const char lower(const char c) {
      return std::tolower(static_cast<unsigned char>(c));
   }
}

