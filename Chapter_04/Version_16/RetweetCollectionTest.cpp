#include "RetweetCollection.h"
#include "Tweet.h"
#include "gmock/gmock.h"

using namespace ::testing;

class ARetweetCollection : public Test
{
public:
    RetweetCollection collection;
};

class ARetweetCollectionWithOneTweet : public Test
{
public:
    RetweetCollection collection;
    void SetUp() override { 
        collection.add(Tweet("msg", "@user")); 
    }
};

TEST_F(ARetweetCollection, IgnoresDuplicateTweetAdded)
{
    Tweet tweet("msg", "@user");
    Tweet duplicate(tweet);
    collection.add(tweet);
    collection.add(duplicate);

    ASSERT_THAT(collection.size(), Eq(1u));
}

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmpty)
{
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollectionWithOneTweet, HasSizeOfOne)
{
    ASSERT_THAT(collection.size(), Eq(1u));
}

MATCHER_P(HasSize, expected, "")
{
    return arg.size() == expected && arg.isEmpty() == (0 == expected);
}

TEST_F(ARetweetCollection, IsEmptyWhenCreated)
{
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated)
{
    ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(ARetweetCollection, HasSizeOfOneAfterTweetAdded)
{
    collection.add(Tweet());

    ASSERT_THAT(collection.size(), Eq(1u));
}

TEST_F(ARetweetCollection, DecreasesSizeAfterRemovingTweet)
{
    collection.add(Tweet());

    collection.remove(Tweet());

    ASSERT_THAT(collection, HasSize(0u));
}

TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsZero)
{
    ASSERT_THAT(collection.size(), Eq(0u));
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, IsNotEmptyWhenItsSizeIsNonZero)
{
    collection.add(Tweet());
    ASSERT_THAT(collection.size(), Gt(0u));
    ASSERT_FALSE(collection.isEmpty());
}