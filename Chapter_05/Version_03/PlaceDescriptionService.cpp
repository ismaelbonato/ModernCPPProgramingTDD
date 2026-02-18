#include "PlaceDescriptionService.h"
#include "AddressExtractor.h"
#include <string>


PlaceDescriptionService::PlaceDescriptionService(Http &http)
    : http(http)
{}

std::string PlaceDescriptionService::summaryDescription(const std::string &latitude,
                                                        const std::string &longitude) const
{
    auto getRequestUrl = "lat=" + latitude + "&lon=" + longitude;
    auto jsonResponse = http.get(getRequestUrl);
    AddressExtractor extractor;
    auto address = extractor.addressFrom(jsonResponse);
    return address.road + ", " + address.city + ", " + address.state + ", "
           + address.country;
}   