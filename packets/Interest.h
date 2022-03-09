//
// Created by rkhan on 09/03/2022.
//

#ifndef NDN_BASIC_INTEREST_H
#define NDN_BASIC_INTEREST_H

#include "Packet.h"

namespace ndn {
    class Interest : public Packet{
    public:
        std::string desired_name;
        bool isInterestPacket() override;
        std::string dump() override;
    };
};


#endif //NDN_BASIC_INTEREST_H
