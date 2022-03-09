//
// Created by rkhan on 09/03/2022.
//

#ifndef NDN_BASIC_PACKET_H
#define NDN_BASIC_PACKET_H

#include <string>

namespace ndn {
    class Packet {
    public:
        std::string body;
        Packet();
        Packet(const std::string& body);
    };
}

#endif //NDN_BASIC_PACKET_H
