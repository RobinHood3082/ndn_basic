//
// Created by rkhan on 09/03/2022.
//

#include "Interest.h"

namespace ndn {
    bool Interest::isInterestPacket() {
        return true;
    }

    std::string Interest::dump() {
        std::string _ret_str;

        return _ret_str;
    }
};