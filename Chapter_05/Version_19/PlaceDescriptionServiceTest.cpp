#include "PlaceDescriptionService.h"
#include "Http.h"
#include "gmock/gmock.h"
#include <string>

using namespace testing;
using namespace std;

class HttpStub : public Http
{
public:
    MOCK_METHOD0(initialize, void());
    MOCK_CONST_METHOD1(get, string(const string &));
};

class APlaceDescriptionService : public Test
{
public:
    static const string ValidLatitude;
    static const string ValidLongitude;
};

const std::string APlaceDescriptionService::ValidLatitude("38.893893");
const std::string APlaceDescriptionService::ValidLongitude("-104.800546");

class APlaceDescriptionService_WithHttpMock : public APlaceDescriptionService
{
public:
    PlaceDescriptionServiceTemplate<HttpStub> service;
};

TEST_F(APlaceDescriptionService_WithHttpMock, MakesHttpRequestToObtainAddress)
{
    string urlStart{
        "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};
    auto expectedURL = urlStart
                       + "lat=" + APlaceDescriptionService::ValidLatitude + "&"
                       + "lon=" + APlaceDescriptionService::ValidLongitude;
    EXPECT_CALL(service.httpRef(), initialize());
    EXPECT_CALL(service.httpRef(), get(expectedURL));

    service.summaryDescription(ValidLatitude, ValidLongitude);
}
