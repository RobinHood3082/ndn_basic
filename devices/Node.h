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
    class Node {
    public:
        std::string name;
        bool operator==(const Node& other) const {
            return this->name == other.name;
        }

        void receive_packet(Packet *p, Node* nd) {}
        void send_packet(Packet *p, Node* nd){}

    private:

        std::vector<ndn::Node> adjacent;
    };
};

#endif //NDN_BASIC_NODE_H
