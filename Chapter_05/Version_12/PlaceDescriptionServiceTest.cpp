#include "PlaceDescriptionService.h"
#include "Http.h"
#include "gmock/gmock.h"
#include <string>

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
public:
    std::string returnResponse;
    std::string expectedURL;
    MOCK_METHOD0(initialize, void());
    MOCK_CONST_METHOD1(get, std::string(const std::string &));

    void verify(const std::string &url) const
    {
        ASSERT_THAT(url, Eq(expectedURL));
    }
};

TEST_F(APlaceDescriptionService, MakesHttpRequestToObtainAddress)
{
    HttpStub httpStub;
    std::string urlStart{
        "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};

    auto expectedURL = urlStart
                       + "lat=" + APlaceDescriptionService::ValidLatitude + "&"
                       + "lon=" + APlaceDescriptionService::ValidLongitude;

    EXPECT_CALL(httpStub, initialize());
    EXPECT_CALL(httpStub, get(expectedURL));

    PlaceDescriptionService service{httpStub};
    service.summaryDescription(ValidLatitude, ValidLongitude);
}

TEST_F(APlaceDescriptionService, FormatsRetrievedAddressIntoSummaryDescription)
{
    NiceMock<HttpStub> httpStub;
    EXPECT_CALL(httpStub, get(_))
        .WillOnce(Return(
            R"({ "address": {
    "road":"Drury Ln",
    "city":"Fountain",
    "state":"CO",
    "country":"US" }})"));

    PlaceDescriptionService service(httpStub);
    auto description = service.summaryDescription(ValidLatitude, ValidLongitude);

    ASSERT_THAT(description, Eq("Drury Ln, Fountain, CO, US"));
}