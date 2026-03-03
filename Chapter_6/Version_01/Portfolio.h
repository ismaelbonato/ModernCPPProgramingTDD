#pragma once

#include <string>

class Portfolio
{
public:
    Portfolio();
    bool IsEmpty() const;
    void Purchase(const std::string &symbol, unsigned int shareCount);
    unsigned int ShareCount(const std::string &symbol) const;

private:
    bool isEmpty;
    unsigned int shareCount;
};