//
// Created by rkhan on 09/03/2022.
//

#ifndef NDN_BASIC_DATA_H
#define NDN_BASIC_DATA_H

#include "Packet.h"

namespace ndn {
    class Data : public Packet{
    public:
        std::string msg;
    };
}


#endif //NDN_BASIC_DATA_H
