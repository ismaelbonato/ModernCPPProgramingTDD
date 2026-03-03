#include "Portfolio.h"

using namespace std;

Portfolio::Portfolio() : shareCount{0u}
{}

bool Portfolio::IsEmpty() const
{
    return shareCount == 0u;
}

void Portfolio::Purchase(const string &symbol, unsigned int newShareCount)
{
    shareCount = newShareCount;
}

unsigned int Portfolio::ShareCount(const string &symbol) const
{
    return shareCount;
}