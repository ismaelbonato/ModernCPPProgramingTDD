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
    return Find<vector<PurchaseRecord>>(purchaseRecords, symbol);
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
    if (shareCount > ShareCount(symbol))
        throw InsufficientSharesException();
    
    transact(symbol, -shareCount, transactionDate); 
}

void Portfolio::InitializePurchaseRecords(const string &symbol)
{
    purchaseRecords[symbol] = vector<PurchaseRecord>();
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
    return Find<long>(holdings, symbol);
}

void Portfolio::Add(const string &symbol, PurchaseRecord &&record)
{
    purchaseRecords[symbol].push_back(record);
}

bool Portfolio::ContainsSymbol(const string &symbol) const
{
    return purchaseRecords.find(symbol) != purchaseRecords.end();
}

void Portfolio::UpdateShareCount(const string &symbol, int shareChange)
{
    holdings[symbol] = ShareCount(symbol) + shareChange;
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

void Portfolio::AddPurchaseRecord(const std::string &symbol,
                                  int shareChange,
                                  const boost::gregorian::date &transactionDate)
{
    if (!ContainsSymbol(symbol))
        InitializePurchaseRecords(symbol);

    Add(symbol, {shareChange, transactionDate});
}