#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

struct PurchaseRecord
{
    PurchaseRecord(int newShareCount, const boost::gregorian::date &newDate)
        : shareCount(newShareCount)
        , date(newDate)
    {}
    long shareCount;
    boost::gregorian::date date;
};
