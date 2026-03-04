#include "Portfolio.h"
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

bool Portfolio::IsEmpty() const
{
    return 0 == holdings.size();
}

void Portfolio::Purchase(const string &symbol,
                         unsigned int shareCount,
                         const boost::gregorian::date &transactionDate)
{
    if (0 == shareCount)
        throw InvalidPurchaseException();
    holdings[symbol] = shareCount + ShareCount(symbol);
    purchases.push_back(PurchaseRecord(shareCount, transactionDate));
}

vector<PurchaseRecord> Portfolio::Purchases(const string &symbol) const
{
    return purchases;
}

void Portfolio::Sell(const std::string &symbol, unsigned int shareCount)
{
    if (shareCount > ShareCount(symbol))
        throw InvalidSellException();
    holdings[symbol] = ShareCount(symbol) - shareCount;
}

unsigned int Portfolio::ShareCount(const string &symbol) const
{
    auto it = holdings.find(symbol);
    if (it == holdings.end())
        return 0;
    return it->second;
}
