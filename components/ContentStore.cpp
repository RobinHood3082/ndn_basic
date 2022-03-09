//
// Created by rkhan on 09/03/2022.
//

#include "ContentStore.h"

namespace ndn {
    Packet ContentStore::search(const std::string &name) {
        Packet _ret_packet;
        for (Frame& _f : cache) {
            if (_f.name == name) {
                _ret_packet = _f.framePacket;
                break;
            }
        }

        return _ret_packet;
    }

    void ContentStore::store(const std::string& name, const Packet& pack) {
        for (Frame& _f : cache) {
            _f.lastUsed++;
        }

        Frame newFrame(name, pack, 0);
        if (this->cache.size() == this->maxSize) {
            // use LRU replacement algorithm
            int mxTime = 0;
            for (Frame& _f : cache) {
                mxTime = std::max(mxTime, _f.lastUsed);
            }

            for (Frame& _f : cache) {
                if (_f.lastUsed == mxTime) {
                    _f = newFrame;
                    return;
                }
            }
        }
        else {
            cache.push_back(newFrame);
        }
    }
};