# pragma once 

#include <drogon/orm/DbClient.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/Exception.h>
#include <drogon/drogon.h> 

#include "models/Assets.h"
#include <string>
#include <optional>
#include <functional>

using namespace drogon;
using namespace drogon_model::investments;

class AssetsRepository{
    public:
        explicit AssetsRepository(drogon::orm::DbClientPtr db) : db_(db) {}

        void findByTicker(const std::string& ticker,
                        std::function<void(const std::vector<Assets>&)> callback,
                        std::function<void(const drogon::orm::DrogonDbException&)> errCallback);
        void create(const Assets& assets,
                    std::function<void(const Assets&)> callback,
                    std::function<void(const drogon::orm::DrogonDbException&)>errCallback);
    private:
        drogon::orm::DbClientPtr db_;
};