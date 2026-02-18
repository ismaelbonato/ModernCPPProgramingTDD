#include "PlaceDescriptionService.h"
#include "Http.h"
#include "gmock/gmock.h"

using namespace testing;

class APlaceDescriptionService : public Test
{
public:
    std::string ValidLatitude;
    std::string ValidLongitude;
};

class HttpStub : public Http
{
    void initialize() override {}
    std::string get(const std::string &url) const override
    {
        return R"({ "address": {
                "road":"Drury Ln",
                "city":"Fountain",
                "state":"CO",
                "country":"US" }})";
    }
};


TEST_F(APlaceDescriptionService, ReturnsDescriptionForValidLocation)
{
    HttpStub httpStub;
    PlaceDescriptionService service{httpStub};
    ValidLatitude = "38.893893";
    ValidLongitude = "-104.800546";
    auto description = service.summaryDescription(ValidLatitude, ValidLongitude);
    ASSERT_THAT(description, Eq("Drury Ln, Fountain, CO, US"));
}