#include "AddressExtractor.h"
#include "gmock/gmock.h"

using namespace testing;
using namespace std;

class AnAddressExtractor : public Test
{
public:
    AddressExtractor extractor;
};

TEST_F(AnAddressExtractor, ParsesAddressFromJSON)
{
    auto json = R"({ "address": {
                "road":"Drury Ln",
                "city":"Fountain",
                "state":"CO",
                "country":"US" }})";
    
    auto address = extractor.addressFrom(json);
    
    ASSERT_THAT(address.road, Eq("Drury Ln"));
    ASSERT_THAT(address.city, Eq("Fountain"));
    ASSERT_THAT(address.state, Eq("CO"));
    ASSERT_THAT(address.country, Eq("US"));
}

TEST_F(AnAddressExtractor, ParsesAddressWithExtraWhitespace)
{
    auto json = R"({  "address":  {
                "road"  :  "Main St"  ,
                "city"  :  "Denver"  ,
                "state"  :  "CO"  ,
                "country"  :  "USA"  }})";
    
    auto address = extractor.addressFrom(json);
    
    ASSERT_THAT(address.road, Eq("Main St"));
    ASSERT_THAT(address.city, Eq("Denver"));
    ASSERT_THAT(address.state, Eq("CO"));
    ASSERT_THAT(address.country, Eq("USA"));
}

TEST_F(AnAddressExtractor, ReturnsEmptyStringsForMissingFields)
{
    auto json = R"({ "address": {
                "road":"Broadway" }})";
    
    auto address = extractor.addressFrom(json);
    
    ASSERT_THAT(address.road, Eq("Broadway"));
    ASSERT_THAT(address.city, Eq(""));
    ASSERT_THAT(address.state, Eq(""));
    ASSERT_THAT(address.country, Eq(""));
}

TEST_F(AnAddressExtractor, HandlesEmptyJSON)
{
    auto json = "";
    
    auto address = extractor.addressFrom(json);
    
    ASSERT_THAT(address.road, Eq(""));
    ASSERT_THAT(address.city, Eq(""));
    ASSERT_THAT(address.state, Eq(""));
    ASSERT_THAT(address.country, Eq(""));
}

TEST_F(AnAddressExtractor, ParsesAddressWithDifferentValues)
{
    auto json = R"({ "address": {
                "road":"1600 Pennsylvania Ave",
                "city":"Washington",
                "state":"DC",
                "country":"United States" }})";
    
    auto address = extractor.addressFrom(json);
    
    ASSERT_THAT(address.road, Eq("1600 Pennsylvania Ave"));
    ASSERT_THAT(address.city, Eq("Washington"));
    ASSERT_THAT(address.state, Eq("DC"));
    ASSERT_THAT(address.country, Eq("United States"));
}
