#include "PlaceDescriptionService.h"
#include "Http.h"
#include "gmock/gmock.h"

using namespace testing;

class APlaceDescriptionService : public Test
{
public:
    static const std::string ValidLatitude;
    static const std::string ValidLongitude;
};

const std::string APlaceDescriptionService::ValidLatitude("38.893893");
const std::string APlaceDescriptionService::ValidLongitude("-104.800546");

class HttpStub : public Http
{
    void initialize() override {}
    std::string get(const std::string &url) const override
    {
        verify(url);
        return R"({ "address": {
                "road":"Drury Ln",
                "city":"Fountain",
                "state":"CO",
                "country":"US" }})";
    }
    void verify(const std::string &url) const
    {
        auto expectedArgs("lat=" + APlaceDescriptionService::ValidLatitude + "&"
                          + "lon=" + APlaceDescriptionService::ValidLongitude);
        ASSERT_THAT(url, EndsWith(expectedArgs));
    }
};

TEST_F(APlaceDescriptionService, ReturnsDescriptionForValidLocation)
{
    HttpStub httpStub;
    PlaceDescriptionService service{httpStub};
    auto description = service.summaryDescription(ValidLatitude, ValidLongitude);
    ASSERT_THAT(description, Eq("Drury Ln, Fountain, CO, US"));
}