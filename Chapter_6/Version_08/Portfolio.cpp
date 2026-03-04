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
    if (0 == shareCount)
        throw InvalidPurchaseException();
    holdings[symbol] = shareCount + ShareCount(symbol);
    purchases.push_back(PurchaseRecord(shareCount, transactionDate));
}

void Portfolio::Sell(const std::string &symbol,
                     unsigned int shareCount,
                     const boost::gregorian::date &transactionDate)
{
    if (shareCount > ShareCount(symbol))
        throw InvalidSellException();
    holdings[symbol] = ShareCount(symbol) - shareCount;
    purchases.push_back(PurchaseRecord(-shareCount, transactionDate));
}

long Portfolio::ShareCount(const string &symbol) const
{
    auto it = holdings.find(symbol);
    if (it == holdings.end())
        return 0;
    return it->second;
}
