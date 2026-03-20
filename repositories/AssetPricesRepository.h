#pragma once 

#include <drogon/orm/DbClient.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/Exception.h> 
#include <drogon/drogon.h>

#include "models/AssetPrices.h"

#include <string>
#include <optional>
#include <functional>

using namespace drogon;
using namespace drogon_model::investments;

class AssetPricesRepository{
    public:
        explicit AssetPricesRepository(drogon::orm::DbClientPtr db) : db_(db) {}

        void findByAssetTicker(const std::string& asset_ticker,
                        std::function<void(const std::vector<AssetPrices>&)> callback,
                        std::function<void(const drogon::orm::DrogonDbException&)> errCallback);
        
        void create(const AssetPrices& asset_ticker,
                    std::function<void(const AssetPrices&)> callback,
                    std::function<void(const drogon::orm::DrogonDbException&)>errCallback);
    private:
        drogon::orm::DbClientPtr db_;
};