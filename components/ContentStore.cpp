//
// Created by rkhan on 09/03/2022.
//

#include "ContentStore.h"

namespace ndn {
    Packet ContentStore::search(const std::string &name) {
        Packet __ret_packet;
        for (std::list<Frame>::iterator it = cache.begin(); it != cache.end(); it++) {
            if (it->name == name) {
                __ret_packet = it->framePacket;
                break;
            }
        }

        return __ret_packet;
    }

    void ContentStore::store(const std::string& name, const Packet& pack) {

    }
};