#include "HttpFactory.h"
#include <string>
#include <memory>

class PlaceDescriptionService
{
public:
    PlaceDescriptionService() = delete;
    PlaceDescriptionService(std::shared_ptr<HttpFactory> httpFactory);

    virtual ~PlaceDescriptionService() {}

    std::string summaryDescription(const std::string &latitude,
                                   const std::string &longitude) const;
    std::string summaryDescription(const std::string &response) const;
    std::string get(const std::string &requestUrl) const;
    std::string createGetRequestUrl(const std::string &latitude,
                                    const std::string &longitude) const;
    std::string keyValue(const std::string &key, const std::string &value) const;

private:
    std::shared_ptr<HttpFactory> httpFactory;
};