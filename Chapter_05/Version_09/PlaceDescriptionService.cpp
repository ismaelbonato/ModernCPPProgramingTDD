#include "PlaceDescriptionService.h"
#include "AddressExtractor.h"
#include <string>

PlaceDescriptionService::PlaceDescriptionService(Http &http)
    : http(http)
{}

std::string PlaceDescriptionService::summaryDescription(
    const std::string &latitude, const std::string &longitude) const
{
    std::string server{"http://open.mapquestapi.com/"};
    std::string document{"nominatim/v1/reverse"};
    std::string url = server + document + "?" + keyValue("format", "json") + "&"
                      + keyValue("lat", latitude) + "&"
                      + keyValue("lon", longitude);
                      
    return summaryDescription(http.get(url));
}

std::string PlaceDescriptionService::summaryDescription(
    const std::string &response) const
{
    AddressExtractor extractor;
    return extractor.summaryDescription(response);
}

std::string PlaceDescriptionService::get(const std::string &requestUrl) const
{
    return http.get(requestUrl);
}

std::string PlaceDescriptionService::createGetRequestUrl(
    const std::string &latitude, const std::string &longitude) const
{
    std::string server{"http://open.mapquestapi.com/"};
    std::string document{"nominatim/v1/reverse"};
    return server + document + "?" + keyValue("format", "json") + "&"
           + keyValue("lat", latitude) + "&" + keyValue("lon", longitude);
}

std::string PlaceDescriptionService::keyValue(const std::string &key,
                                              const std::string &value) const
{
    return key + "=" + value;
}