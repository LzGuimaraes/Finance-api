#include "PortfolioSnapshotsRepository.h"
#include <drogon/orm/Result.h>

using namespace drogon::orm;

void PortfolioSnapshotsRepository::findByUserId(
    const int userId,
    std::function<void(const std::vector<PortfolioSnapshots>&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {

    Mapper<PortfolioSnapshots> mapper(db_);
    mapper.findBy(
        Criteria(PortfolioSnapshots::Cols::_user_id, CompareOperator::EQ, userId),
        callback,
        errCallback
    );
}

void PortfolioSnapshotsRepository::create(
    const PortfolioSnapshots& portfolioSnapshot,
    std::function<void(const PortfolioSnapshots&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    Mapper<PortfolioSnapshots> mapper(db_);
    mapper.insert(
        portfolioSnapshot,
        callback,
        errCallback
    );
}    