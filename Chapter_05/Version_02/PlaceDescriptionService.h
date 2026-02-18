#include "Http.h"
#include <string>

class PlaceDescriptionService
{
public:
    PlaceDescriptionService(Http &http);

    std::string summaryDescription(const std::string &latitude,
                                   const std::string &longitude) const;

private:
    Http &http;
};