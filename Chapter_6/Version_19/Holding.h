#pragma once

#include "Portfolio.h"
#include "PurchaseRecord.h"
#include <vector>
#include <numeric>

class Holding
{
public:
    void Add(PurchaseRecord &record) { purchaseRecords.push_back(record); }
    std::vector<PurchaseRecord> Purchases() const { return purchaseRecords; }

    long ShareCount() const
    {
        return accumulate(purchaseRecords.begin(),
                          purchaseRecords.end(),
                          0,
                          [](long total, PurchaseRecord record) {
                              return total + record.shareCount;
                          });
    }

    std::vector<PurchaseRecord> purchaseRecords;
};