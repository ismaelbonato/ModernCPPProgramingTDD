#include "Portfolio.h"

using namespace std;

Portfolio::Portfolio()
    : isEmpty{true}
    , shareCount{0u}
{}

bool Portfolio::IsEmpty() const
{
    return isEmpty;
}

void Portfolio::Purchase(const string &symbol, unsigned int newShareCount)
{
    isEmpty = false;
    shareCount = newShareCount;
}

unsigned int Portfolio::ShareCount(const string &symbol) const
{
    return shareCount;
}