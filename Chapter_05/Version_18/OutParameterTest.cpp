#include "gmock/gmock.h"

using namespace ::testing;

class DifficultCollaborator
{
public:
    virtual bool calculate(int &result) { throw true; }
};

class Target
{
public:
     int execute(DifficultCollaborator &diff)
    {
        int i;
        bool value = diff.calculate(i);
        if (!value) {
            return 0;
        }
        return i;
    }
};

class DifficultCollaboratorMock : public DifficultCollaborator
{
public:
    MOCK_METHOD1(calculate, bool(int&));
};

TEST(ATarget, CalculateTest)
{
    DifficultCollaboratorMock difficult;
    Target calc;
    EXPECT_CALL(difficult, calculate(_))
        .WillOnce(DoAll(SetArgReferee<0>(3), Return(true)));

    auto result = calc.execute(difficult);
    ASSERT_THAT(result, Eq(3));
}