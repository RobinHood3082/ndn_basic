//
// Created by rkhan on 09/03/2022.
//

#ifndef NDN_BASIC_CONTENTSTORE_H
#define NDN_BASIC_CONTENTSTORE_H

#include <string>
#include "../cmake-build-debug/packets/Packet.h"
#include <list>
#include <iterator>

namespace ndn {
    class ContentStore {
    private:
        int size;
        struct frame {
            std::string name;
            Packet framePacket;
            int lastUsed;
        };

        std::list<frame> cache;

    public:
        Packet search(const std::string& name);
        void store(const std::string& name, const Packet& pack);
        void setMaxSize(const int& size);
        std::string dump();
    };
}

#endif //NDN_BASIC_CONTENTSTORE_H
