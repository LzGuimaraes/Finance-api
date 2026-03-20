#pragma once

#include <drogon/orm/DbClient.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/Exception.h>
#include <drogon/drogon.h>

#include "models/Transactions.h"

#include <string>
#include <optional>
#include <functional>

using namespace drogon;
using namespace drogon_model::investments;

class TransactionsRepository{
    public:
        explicit TransactionsRepository(drogon::orm::DbClientPtr db) : db_(db) {}
        
        void findByUserId(const int userId,
                        std::function<void(const std::vector<Transactions>&)> callback,
                        std::function<void(const drogon::orm::DrogonDbException&)> errCallback);
        
        void create(const Transactions& transaction,
                    std::function<void(const Transactions&)> callback,
                    std::function<void(const drogon::orm::DrogonDbException&)>errCallback);
        private:        
            drogon::orm::DbClientPtr db_;  
    };