#include "AssetsRepository.h"
#include <drogon/orm/Result.h>

using namespace drogon::orm;

void AssetsRepository::findByTicker(
    const std::string &ticker,
    std::function<void(const std::vector<Assets>&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    
    Mapper<Assets> mapper(db_);
    mapper.findBy(
        Criteria(Assets::Cols::_ticker, CompareOperator::EQ, ticker),
        callback,
        errCallback
    );
}

void AssetsRepository::create(
    const Assets &assets,
    std::function<void(const Assets&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    Mapper<Assets> mapper(db_);
    mapper.insert(
        assets,
        callback,
        errCallback
    );
}
