//
// Created by rkhan on 09/03/2022.
//

#ifndef NDN_BASIC_PENDINGINTERESTTABLE_H
#define NDN_BASIC_PENDINGINTERESTTABLE_H

#include <string>
#include <tuple>
#include <list>
#include <vector>

const int STATE_JUST_RECIEVED = 0;
const int STATE_FORWARDED = 1;

namespace ndn {
    class PendingInterestTable {
    public:
        std::list <std::tuple<std::string, std::string, int>> interestStates;
        // 0: incomingRouterName, 1: interestName, 2: status

        bool check(const std::string& incomingRouterName, const std::string& interestName);
        void newPITEntry(const std::string& incomingRouterName, const std::string& interestName);
        std::vector<std::string> interestAcceptedFor(const std::string& interestName);
    };
}

#endif //NDN_BASIC_PENDINGINTERESTTABLE_H
