#include "PlaceDescriptionService.h"
#include "AddressExtractor.h"

using namespace std;

PlaceDescriptionService::PlaceDescriptionService(Http &http)
    : http(http)
{}

string PlaceDescriptionService::summaryDescription(const std::string &latitude,
                                                   const std::string &longitude) const
{
    auto getRequestUrl = "";
    auto jsonResponse = http.get(getRequestUrl);
    AddressExtractor extractor;
    auto address = extractor.addressFrom(jsonResponse);
    return address.road + ", " + address.city + ", " + address.state + ", "
           + address.country;
}   