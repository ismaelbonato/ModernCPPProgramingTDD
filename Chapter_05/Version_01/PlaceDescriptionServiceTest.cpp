#include "Http.h"
#include "gmock/gmock.h"

using namespace testing;

class HttpStub : public Http
{
    void initialize() override {}
    std::string get(const std::string &url) const override { return "???"; }
};

class PlaceDescriptionService
{
public:
    PlaceDescriptionService(Http &http)
        : http{http}
    {}
    std::string summaryDescription(const std::string &latitude,
                                   const std::string &longitude) const
    {
        // ... use http to get description for location
        return http.get("http://example.com/description?lat=" + latitude
                        + "&lon=" + longitude);
    }

private:
    Http &http;
};

class APlaceDescriptionService : public Test
{
public:
    std::string ValidLatitude;
    std::string ValidLongitude;
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