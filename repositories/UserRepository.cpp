#include "UserRepository.h"
#include <drogon/orm/Result.h>
using namespace drogon::orm;

void UserRepository::findByEmail(
    const std::string& email,
    std::function<void(const std::optional<Users>&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    
    Mapper<Users> mapper(db_);
    mapper.findBy(
        Criteria(Users::Cols::_email, CompareOperator::EQ, email),
        [callback](const std::vector<Users>& users) {
            if (!users.empty()) {
                callback(users[0]);
            } else {
                callback(std::nullopt);
            }
        },
        errCallback
    );
}

void UserRepository::create(
    const Users& user,
    std::function<void(const Users&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    Mapper<Users> mapper(db_);
    mapper.insert(
        user,
        callback,
        errCallback
    );
}