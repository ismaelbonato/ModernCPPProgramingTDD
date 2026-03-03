#include "Portfolio.h"
using namespace std;


Portfolio::Portfolio()
{
}

bool Portfolio::IsEmpty() const
{
    return 0 == holdings.size();
}
void Portfolio::Purchase(const string &symbol, unsigned int shareCount)
{
    if (0 == shareCount)
        throw InvalidPurchaseException();
    holdings[symbol] = shareCount + ShareCount(symbol);
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