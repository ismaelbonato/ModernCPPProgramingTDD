#include "Http.h"
#include <string>

class PlaceDescriptionService
{
public:
    PlaceDescriptionService(Http &http);

    std::string summaryDescription(const std::string &latitude,
                                   const std::string &longitude) const;
    std::string summaryDescription(const std::string &response) const;
    std::string get(const std::string &requestUrl) const;
    std::string createGetRequestUrl(const std::string &latitude,
                                    const std::string &longitude) const;
    std::string keyValue(const std::string &key, const std::string &value) const;

private:
    Http &http;
};