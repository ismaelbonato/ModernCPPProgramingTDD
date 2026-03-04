#include "Portfolio.h"
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

bool Portfolio::IsEmpty() const
{
    return 0 == holdings.size();
}

vector<PurchaseRecord> Portfolio::Purchases(const string &symbol) const
{
    return purchaseRecords.find(symbol)->second;
}

void Portfolio::Purchase(const string &symbol,
                         int shareCount,
                         const boost::gregorian::date &transactionDate)
{
    transact(symbol, shareCount, transactionDate);
}

void Portfolio::Sell(const std::string &symbol,
                     unsigned int shareCount,
                     const boost::gregorian::date &transactionDate)
{
    TrownIfInsufficientSharesToSell(symbol, shareCount);
    transact(symbol, -shareCount, transactionDate);
}

void Portfolio::transact(const std::string &symbol,
                         int shareChange,
                         const boost::gregorian::date &transactionDate)
{
    ThrowIfShareCountIsZero(shareChange);
    UpdateShareCount(symbol, shareChange);
    AddPurchaseRecord(symbol, shareChange, transactionDate);
}

long Portfolio::ShareCount(const string &symbol) const
{
    auto it = holdings.find(symbol);
    if (it == holdings.end())
        return 0;
    return it->second;
}

void Portfolio::TrownIfInsufficientSharesToSell(const std::string &symbol,
                                                unsigned int shareCount)
{
    if (shareCount > ShareCount(symbol))
        throw InsufficientSharesException();
}

void Portfolio::ThrowIfShareCountIsZero(int shareChange)
{
    if (0 == shareChange)
        throw ShareCountCannotBeZeroException();
}

void Portfolio::UpdateShareCount(const std::string &symbol, int shareChange)
{
    holdings[symbol] = ShareCount(symbol) + shareChange;
}

void Portfolio::AddPurchaseRecord(const std::string &symbol,
                                  int shareChange,
                                  const boost::gregorian::date &transactionDate)
{
    purchases.push_back(PurchaseRecord(shareChange, transactionDate));
    auto it = purchaseRecords.find(symbol);
    if (it == purchaseRecords.end()) {
        purchaseRecords[symbol] = vector<PurchaseRecord>();
    }
    purchaseRecords[symbol].push_back(
        PurchaseRecord(shareChange, transactionDate));
}