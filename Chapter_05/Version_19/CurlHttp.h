#pragma once

#include "Http.h"
#include <string>

class CurlHttp : public Http
{
public:
    CurlHttp() = default;
    ~CurlHttp();  
    void initialize() override;
    std::string get(const std::string &url) const override;    
};  