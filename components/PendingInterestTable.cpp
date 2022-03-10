//
// Created by rkhan on 09/03/2022.
//

#include <queue>
#include "PendingInterestTable.h"

namespace ndn {
    bool PendingInterestTable::check(const std::string& incomingRouterName, const std::string& interestName) {
        bool _ret_ = false;
        for (auto& _tuple_ : interestStates) {
            if (std::get<1>(_tuple_) == interestName) {
                interestStates.emplace_back(incomingRouterName, interestName, STATE_FORWARDED);
                return true;
            }
        }

        return false;
    }

    void PendingInterestTable::newPITEntry(const std::string &incomingRouterName, const std::string &interestName) {
        interestStates.emplace_back(incomingRouterName, interestName, STATE_JUST_RECIEVED);
    }

    std::vector<std::string> PendingInterestTable::interestAcceptedFor(const std::string &interestName) {
        std::vector<std::string> routerInterfaceNames;
        std::queue<std::list <std::tuple<std::string, std::string, int>>::iterator> deleteQueue;

        for (auto it = interestStates.begin(); it != interestStates.end(); it++) {
            if (std::get<1>(*it) == interestName) {
                deleteQueue.push(it);
                routerInterfaceNames.push_back(std::get<0>(*it));
            }
        }

        while (!deleteQueue.empty()) {
            auto it = deleteQueue.front();
            deleteQueue.pop();
            interestStates.erase(it);
        }

        return routerInterfaceNames;
    }
}