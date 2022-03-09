//
// Created by rkhan on 09/03/2022.
//

#ifndef NDN_BASIC_NODE_H
#define NDN_BASIC_NODE_H
#include <string>
#include <unordered_map>
#include <vector>
#include "../packets/Packet.h"

namespace ndn {
    class node {
    public:
        std::string name;
        bool operator==(const node& other) const {
            return this->name == other.name;
        }

        void receive_packet(Packet *p, node* nd) {}
        void send_packet(Packet *p, node* nd){}

    private:

        std::vector<ndn::node> adjacent;
    };
};

#endif //NDN_BASIC_NODE_H
