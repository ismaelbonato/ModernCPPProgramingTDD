#pragma once

#include "AddressExtractor.h"
#include "Http.h"

#include <string>

template<typename HTTP>
class PlaceDescriptionServiceTemplate
{
public:
    // ...
    // mocks in tests need the reference
    std::string summaryDescription(const std::string &latitude,
                                   const std::string &longitude)
    {
        std::string server{"http://open.mapquestapi.com/"};
        std::string document{"nominatim/v1/reverse"};
        std::string url = server + document + "?" + keyValue("format", "json")
                          + "&" + keyValue("lat", latitude) + "&"
                          + keyValue("lon", longitude);

        auto request = createGetRequestUrl(latitude, longitude);
        auto response = get(request);
        return summaryDescription(response);
    }
    HTTP &httpRef() { return http; }

private:
    std::string summaryDescription(const std::string &response) const
    {
        AddressExtractor extractor;
        return extractor.summaryDescription(response);
    }
    std::string createGetRequestUrl(const std::string &latitude,
                                    const std::string &longitude) const
    {
        std::string server{"http://open.mapquestapi.com/"};
        std::string document{"nominatim/v1/reverse"};
        return server + document + "?" + keyValue("format", "json") + "&"
               + keyValue("lat", latitude) + "&" + keyValue("lon", longitude);
    }

    std::string get(const std::string &url)
    {
        http.initialize();
        return http.get(url);
    }

    std::string keyValue(const std::string &key, const std::string &value) const
    {
        return key + "=" + value;
    } // ...
    HTTP http;
};

class Http;
using PlaceDescriptionService = PlaceDescriptionServiceTemplate<Http>;