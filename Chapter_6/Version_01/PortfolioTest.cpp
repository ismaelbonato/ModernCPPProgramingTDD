#include "Portfolio.h"
#include "gmock/gmock.h"

using namespace testing;

class APortfolio : public Test
{
public:
    Portfolio portfolio;
};

TEST_F(APortfolio, IsEmptyWhenCreated)
{
    ASSERT_TRUE(portfolio.IsEmpty());
}

TEST_F(APortfolio, IsNotEmptyAfterPurchase)
{
    portfolio.Purchase("IBM", 1);
}

TEST_F(APortfolio, AnswersZeroForShareCountOfUnpurchasedSymbol)
{
    ASSERT_THAT(portfolio.ShareCount("AAPL"), Eq(0u));
}

TEST_F(APortfolio, AnswersShareCountForPurchasedSymbol)
{
    portfolio.Purchase("IBM", 2);
    ASSERT_THAT(portfolio.ShareCount("IBM"), Eq(2u));
}