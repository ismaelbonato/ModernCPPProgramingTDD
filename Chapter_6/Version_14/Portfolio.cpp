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
    return purchases;
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

void Portfolio::transact(const std::string &symbol,
                         int shareChange,   
                         const boost::gregorian::date &transactionDate)
{
    if (0 == shareChange)
        throw ShareCountCannotBeZeroException();

    holdings[symbol] = ShareCount(symbol) + shareChange;
    purchases.push_back(PurchaseRecord(shareChange, transactionDate));
}

long Portfolio::ShareCount(const string &symbol) const
{
    auto it = holdings.find(symbol);
    if (it == holdings.end())
        return 0;
    return it->second;
}

