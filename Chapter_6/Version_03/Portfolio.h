#pragma once

#include <string>
#include <unordered_map>

class InvalidSellException : public std::exception {};
class InvalidPurchaseException : public std::exception {};

class Portfolio
{
public:
    Portfolio();
    bool IsEmpty() const;
    void Purchase(const std::string &symbol, unsigned int shareCount);
    unsigned int ShareCount(const std::string &symbol) const;
    void Sell(const std::string &symbol, unsigned int shareCount);

private:
    std::unordered_map<std::string, unsigned int> holdings;
};

