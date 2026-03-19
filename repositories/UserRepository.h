#pragma once

#include <drogon/orm/DbClient.h>
#include <drogon/orm/Exception.h>
#include <drogon/drogon.h>

#include "models/Users.h"

#include <string>
#include <optional>
#include <functional>

using namespace drogon;
using namespace drogon_model::investments;

class UserRepository{
    public:
        explicit UserRepository(drogon::orm::DbClientPtr db) : db_(db) {}

        void findByEmail(const std::string& email,
                        std::function<void(const std::optional<Users>&)> callback,
                        std::function<void(const drogon::orm::DrogonDbException&)> errCallback);
        void create(const Users& user,
                    std::function<void(const Users&)> callback,
                    std::function<void(const drogon::orm::DrogonDbException&)>errCallback);
    private:
        drogon::orm::DbClientPtr db_;
};