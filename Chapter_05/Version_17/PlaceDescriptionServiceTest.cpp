#include "PlaceDescriptionService.h"
#include "Http.h"
#include "gmock/gmock.h"
#include <memory>
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
    MOCK_METHOD0(initialize, void());
    MOCK_CONST_METHOD1(get, std::string(const std::string &));
};

class PlaceDescriptionService_StubHttpService : public PlaceDescriptionService
{
public:
    PlaceDescriptionService_StubHttpService(std::shared_ptr<HttpStub> newHttpStub)
        : httpStub{newHttpStub}
    {}
    std::shared_ptr<Http> httpService() const override { return httpStub; }
    std::shared_ptr<Http> httpStub;
};

TEST_F(APlaceDescriptionService, MakesHttpRequestToObtainAddress)
{
    InSequence forceExpectationOrder;
    std::shared_ptr<HttpStub> httpStub{std::make_shared<HttpStub>()};
    std::string urlStart{
        "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};
   
    auto expectedURL = urlStart
                      + "lat=" + APlaceDescriptionService::ValidLatitude + "&"
                      + "lon=" + APlaceDescriptionService::ValidLongitude;

    EXPECT_CALL(*httpStub, initialize());
    EXPECT_CALL(*httpStub, get(expectedURL));
    PlaceDescriptionService_StubHttpService service{httpStub};

    service.summaryDescription(ValidLatitude, ValidLongitude);
}