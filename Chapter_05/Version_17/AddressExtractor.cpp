#include "AddressExtractor.h"

using namespace std;

namespace {
    string extractValue(const string &json, const string &key)
    {
        // Find the key in the JSON
        string searchKey = "\"" + key + "\"";
        size_t keyPos = json.find(searchKey);
        if (keyPos == string::npos)
            return "";
        
        // Find the colon after the key
        size_t colonPos = json.find(':', keyPos);
        if (colonPos == string::npos)
            return "";
        
        // Find the opening quote of the value
        size_t valueStart = json.find('\"', colonPos);
        if (valueStart == string::npos)
            return "";
        
        valueStart++; // Move past the opening quote
        
        // Find the closing quote
        size_t valueEnd = json.find('\"', valueStart);
        if (valueEnd == string::npos)
            return "";
        
        return json.substr(valueStart, valueEnd - valueStart);
    }
}

Address AddressExtractor::addressFrom(const string &json) const
{
    Address address;
    
    // Extract each field from the JSON structure
    address.road = extractValue(json, "road");
    address.city = extractValue(json, "city");
    address.state = extractValue(json, "state");
    address.country = extractValue(json, "country");
    
    return address;
}

string AddressExtractor::summaryDescription(const string &json) const
{
    auto address = addressFrom(json);
    return address.road + ", " + address.city + ", " + address.state + ", " + address.country;
}
