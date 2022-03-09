//
// Created by rkhan on 09/03/2022.
//

#include "Packet.h"

namespace ndn {
    Packet::Packet() {
        this->body = "";
    }

    Packet::Packet(const std::string& body) {
        this->body = body;
    }
};