#pragma once

#include "Http.h"
#include <memory>

class HttpFactory
{
public:
    HttpFactory();

    std::shared_ptr<Http> get() const;
    void reset();
    void setInstance(std::shared_ptr<Http> newInstance);

private:
    std::shared_ptr<Http> instance;
};
