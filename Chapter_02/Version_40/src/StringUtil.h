#pragma once

#include <string>

namespace utils {
   const std::string head(const std::string& word);
   const std::string tail(const std::string& word);
   const std::string zeroPad(const std::string& text, const unsigned int toLength);
   const std::string upperFront(const std::string& string);
}
