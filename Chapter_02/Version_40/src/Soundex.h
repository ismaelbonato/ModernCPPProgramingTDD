#pragma once

#include <string>
    
class Soundex
{
public:
    static const size_t MaxCodeLength{4};

    std::string encode(const std::string &word) const;
    std::string encodedDigit(char letter) const;

private:
    const std::string NotADigit{"*"};
    std::string encodedDigits(const std::string &word) const;

    void encodeHead(std::string &encoding, const std::string &word) const;
    void encodeTail(std::string &encoding, const std::string &word) const;
    void encodeLetter(std::string &encoding, char letter, char lastLetter) const;
    std::string lastDigit(const std::string &encoding) const;
    bool isComplete(const std::string &encoding) const;
};