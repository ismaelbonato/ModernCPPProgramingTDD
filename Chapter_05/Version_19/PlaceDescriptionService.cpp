#include "PlaceDescriptionService.h"
#include "AddressExtractor.h"
#include "CurlHttp.h"
#include "HttpFactory.h"
#include <memory>
#include <string>

PlaceDescriptionService::PlaceDescriptionService(
    std::shared_ptr<HttpFactory> httpFactory)
    : httpFactory(httpFactory)
{}

std::string PlaceDescriptionService::summaryDescription(
    const std::string &latitude, const std::string &longitude) const
{
    std::string server{"http://open.mapquestapi.com/"};
    std::string document{"nominatim/v1/reverse"};
    std::string url = server + document + "?" + keyValue("format", "json") + "&"
                      + keyValue("lat", latitude) + "&"
                      + keyValue("lon", longitude);

    auto request = createGetRequestUrl(latitude, longitude);
    auto response = get(request);
    return summaryDescription(response);
}

std::string PlaceDescriptionService::summaryDescription(
    const std::string &response) const
{
    AddressExtractor extractor;
    return extractor.summaryDescription(response);
}

std::string PlaceDescriptionService::get(const std::string &url) const
{
    auto http = httpFactory->get();
    http->initialize();
    return http->get(url);
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