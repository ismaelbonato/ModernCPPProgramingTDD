#include "PlaceDescriptionService.h"
#include "Http.h"
#include "gmock/gmock.h"
#include <memory>
#include <string>
#include "HttpFactory.h"

using namespace testing;    
using namespace std;

class HttpStub : public Http
{
public:
    MOCK_METHOD0(initialize, void());
    MOCK_CONST_METHOD1(get, std::string(const std::string &));
};

class APlaceDescriptionService : public Test
{
public:
    static const string ValidLatitude;
    static const string ValidLongitude;
    shared_ptr<HttpStub> httpStub;
    shared_ptr<HttpFactory> factory;
    shared_ptr<PlaceDescriptionService> service;
    virtual void SetUp() override
    {
        factory = make_shared<HttpFactory>();
        service = make_shared<PlaceDescriptionService>(factory);
    }
    void TearDown() override
    {
        factory.reset();
        httpStub.reset();
    }
};

const std::string APlaceDescriptionService::ValidLatitude("38.893893");
const std::string APlaceDescriptionService::ValidLongitude("-104.800546");

class APlaceDescriptionService_WithHttpMock : public APlaceDescriptionService
{
public:
    void SetUp() override
    {
        APlaceDescriptionService::SetUp();
        httpStub = make_shared<HttpStub>();
        factory->setInstance(httpStub);
    }
};
TEST_F(APlaceDescriptionService_WithHttpMock, MakesHttpRequestToObtainAddress)
{
    string urlStart{
        "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};
    auto expectedURL = urlStart
                       + "lat=" + APlaceDescriptionService::ValidLatitude + "&"
                       + "lon=" + APlaceDescriptionService::ValidLongitude;
    EXPECT_CALL(*httpStub, initialize());
    EXPECT_CALL(*httpStub, get(expectedURL));
    service->summaryDescription(ValidLatitude, ValidLongitude);
}