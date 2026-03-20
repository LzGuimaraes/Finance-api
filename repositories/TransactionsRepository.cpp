#include "TransactionsRepository.h"
#include <drogon/orm/Result.h>
using namespace drogon::orm;

void TransactionsRepository::findByUserId(
    const int userId,
    std::function<void(const std::vector<Transactions>&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    
    Mapper<Transactions> mapper(db_);
    mapper.findBy(
        Criteria(Transactions::Cols::_user_id, CompareOperator::EQ, userId),
        callback,
        errCallback
    );
}

void TransactionsRepository::create(
    const Transactions& transaction,
    std::function<void(const Transactions&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    Mapper<Transactions> mapper(db_);
    mapper.insert(
        transaction,
        callback,
        errCallback
    );
}
