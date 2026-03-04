#include "Portfolio.h"
#include "gmock/gmock.h"
#include <boost/date_time/gregorian/greg_date.hpp>

using namespace testing;
using namespace boost::gregorian;

class APortfolio : public Test
{
public:
    Portfolio portfolio;
};

const std::string AAPL("AAPL");
const std::string IBM("IBM");
const std::string SAMSUNG("SAMSUNG");

TEST_F(APortfolio, AnswersThePurchaseRecordForASinglePurchase)
{
    date purchaseDate(2024, Jun, 1);

    portfolio.Purchase(SAMSUNG, 5, purchaseDate);
    auto purchases = portfolio.Purchases(SAMSUNG);
    auto purchase = purchases[0];
    ASSERT_THAT(purchase.ShareCount, Eq(5u));
    ASSERT_THAT(purchase.Date, Eq(purchaseDate));
}

TEST_F(APortfolio, IsEmptyWhenCreated)
{
    ASSERT_TRUE(portfolio.IsEmpty());
}

TEST_F(APortfolio, IsNotEmptyAfterPurchase)
{
    portfolio.Purchase(IBM, 1);
}

TEST_F(APortfolio, AnswersZeroForShareCountOfUnpurchasedSymbol)
{
    ASSERT_THAT(portfolio.ShareCount(AAPL), Eq(0u));
}

TEST_F(APortfolio, AnswersShareCountForPurchasedSymbol)
{
    portfolio.Purchase(IBM, 2);
    ASSERT_THAT(portfolio.ShareCount(IBM), Eq(2u));
}

TEST_F(APortfolio, ThrowsOnPurchaseOfZeroShares)
{
    ASSERT_THROW(portfolio.Purchase(IBM, 0), InvalidPurchaseException);
}

TEST_F(APortfolio, AnswersShareCountForAppropriateSymbol)
{
    portfolio.Purchase(IBM, 2);
    portfolio.Purchase(AAPL, 3);
    ASSERT_THAT(portfolio.ShareCount(IBM), Eq(2u));
    ASSERT_THAT(portfolio.ShareCount(AAPL), Eq(3u));
}

TEST_F(APortfolio, ShareCountReflectsAccumulatedPurchasesOfSameSymbol)
{
    portfolio.Purchase(IBM, 2);
    portfolio.Purchase(IBM, 3);
    ASSERT_THAT(portfolio.ShareCount(IBM), Eq(5u));
}

TEST_F(APortfolio, ReducesShareCountOfSymbolOnSell)
{
    portfolio.Purchase(IBM, 5);
    portfolio.Sell(IBM, 2);
    ASSERT_THAT(portfolio.ShareCount(IBM), Eq(3u));
}

TEST_F(APortfolio, ThrowsWhenSellingMoreSharesThanPurchased)
{
    portfolio.Purchase(IBM, 5);
    ASSERT_THROW(portfolio.Sell(IBM, 6), InvalidSellException);
}