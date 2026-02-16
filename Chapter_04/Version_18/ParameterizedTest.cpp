#include "gmock/gmock.h"

struct SumCase
{
    int a, b, expected;
    SumCase(int anA, int aB, int anExpected)
        : a(anA)
        , b(aB)
        , expected(anExpected)
    {}
};

class Adder
{
public:
    static int sum(int a, int b) { return a + b; }
};

class AnAdder : public testing::TestWithParam<SumCase>
{};

TEST_P(AnAdder, GeneratesLotsOfSumsFromTwoNumbers)
{
    SumCase input = GetParam();
    ASSERT_THAT(Adder::sum(input.a, input.b), testing::Eq(input.expected));
}

SumCase sums[] = {SumCase(1, 1, 2), SumCase(1, 2, 3), SumCase(2, 2, 4)};

INSTANTIATE_TEST_CASE_P(BulkTest, AnAdder, testing::ValuesIn(sums));