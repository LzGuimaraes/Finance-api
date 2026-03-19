#include "UserRepository.h"
#include <drogon/orm/Result.h>
using namespace drogon::orm;

void UserRepository::findByEmail(
    const std::string& email,
    std::function<void(const std::optional<Users>&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback) {
    
    db_->execSqlAsync(
        "SELECT * FROM users WHERE email = $1",
        [callback](const Result& result) {
            if (result.empty()) {
                callback(std::nullopt);
                return;
            }

            Users user(result[0]);
            callback(user);
        },
        errCallback,
        email
    );
}

void UserRepository::create(
    const Users& user,
    std::function<void(const Users&)> callback,
    std::function<void(const drogon::orm::DrogonDbException&)> errCallback)
{
    db_->execSqlAsync(
        "INSERT INTO users (name, email, password_hash) VALUES ($1, $2, $3) RETURNING *",
        [callback](const Result& result) {
            Users created(result[0]);
            callback(created);
        },
        errCallback,
        user.getName(),
        user.getEmail(),
        user.getPasswordHash());
}