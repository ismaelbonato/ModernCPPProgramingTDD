#pragma once

#include <boost/date_time/gregorian/greg_date.hpp>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/date_time/gregorian/gregorian.hpp>

template<typename T>
T Find(const std::unordered_map<std::string, T> &map, const std::string &key)
{
    auto it = map.find(key);
    return it == map.end() ? T{} : it->second;
}

class InsufficientSharesException : public std::exception
{};

class ShareCountCannotBeZeroException : public std::exception
{};

struct PurchaseRecord
{
    PurchaseRecord(int newShareCount, const boost::gregorian::date &newDate)
        : shareCount(newShareCount)
        , date(newDate)
    {}
    long shareCount;
    boost::gregorian::date date;
};

class Portfolio
{
public:
    Portfolio() = default;
    bool IsEmpty() const;
    void Purchase(const std::string &symbol,
                  int shareCount,
                  const boost::gregorian::date &transactionDate);

    void Sell(const std::string &symbol,
              unsigned int shareCount,
              const boost::gregorian::date &transactionDate);

    long ShareCount(const std::string &symbol) const;
    std::vector<PurchaseRecord> Purchases(const std::string &symbol) const;

private:
    void InitializePurchaseRecords(const std::string &symbol);
    void Add(const std::string &symbol, PurchaseRecord &&record);
    bool ContainsSymbol(const std::string &symbol) const;
    void transact(const std::string &symbol,
                  int shareChange,
                  const boost::gregorian::date &transactionDate);

    void TrownIfInsufficientSharesToSell(const std::string &symbol,
                                         unsigned int shareCount);
    void ThrowIfShareCountIsZero(int shareChange);
    void UpdateShareCount(const std::string &symbol, int shareChange);
    void AddPurchaseRecord(const std::string &symbol,
                           int shareChange,
                           const boost::gregorian::date &transactionDate);

private:
    std::unordered_map<std::string, long> holdings;
    std::vector<PurchaseRecord> purchases;
    std::unordered_map<std::string, std::vector<PurchaseRecord>> purchaseRecords;
};
