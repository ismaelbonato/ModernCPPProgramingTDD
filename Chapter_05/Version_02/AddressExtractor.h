#ifndef ADDRESS_EXTRACTOR_H
#define ADDRESS_EXTRACTOR_H

#include <string>

struct Address
{
    std::string road;
    std::string city;
    std::string state;
    std::string country;
};

class AddressExtractor
{
public:
    Address addressFrom(const std::string &json) const;
};

#endif // ADDRESS_EXTRACTOR_H
