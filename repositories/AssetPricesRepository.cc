#include "AssetPricesRepository.h"
#include <drogon/orm/Result.h>

using namespace drogon::orm;

void AssetPricesRepository::findByAssetTicker(
    const std::string& asset_ticker,
    std::function<void(const std::vector<AssetPrices>&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    
    Mapper<AssetPrices> mapper(db_);
    mapper.findBy(
        Criteria(AssetPrices::Cols::_asset_ticker, CompareOperator::EQ, asset_ticker),
        callback,
        errCallback
    );
}

void AssetPricesRepository::create(
    const AssetPrices &assetPrice,
    std::function<void(const AssetPrices&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    Mapper<AssetPrices> mapper(db_);
    mapper.insert(
        assetPrice,
        callback,
        errCallback
    );
}