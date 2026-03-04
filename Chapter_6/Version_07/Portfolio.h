#pragma once

#include <boost/date_time/gregorian/greg_date.hpp>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/date_time/gregorian/gregorian.hpp>

class InvalidSellException : public std::exception
{};
class InvalidPurchaseException : public std::exception
{};

struct PurchaseRecord
{
    PurchaseRecord(unsigned int shareCount, const boost::gregorian::date &date)
        : ShareCount(shareCount)
        , Date(date)
    {}
    unsigned int ShareCount;
    boost::gregorian::date Date;
};

class Portfolio
{
public:
    Portfolio() = default;
    bool IsEmpty() const;
    void Purchase(const std::string &symbol,
                  unsigned int shareCount,
                  const boost::gregorian::date &transactionDate);

    void Sell(const std::string &symbol, unsigned int shareCount);
    unsigned int ShareCount(const std::string &symbol) const;
    std::vector<PurchaseRecord> Purchases(const std::string &symbol) const;
    
private:
    std::unordered_map<std::string, unsigned int> holdings;
    std::vector<PurchaseRecord> purchases;
};
