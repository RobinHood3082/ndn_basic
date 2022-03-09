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

    void ContentStore::setMaxSize(const int &size) {
        this->maxSize = size;
    }

    std::string ContentStore::dump() {
        std::string _ret_str;
        _ret_str += std::to_string(maxSize); _ret_str += '\n';
        _ret_str += std::to_string(cache.size()); _ret_str += '\n';
        for (Frame& _f : cache) {
            _ret_str += _f.dump();
            _ret_str += '\n';
        }

        return _ret_str;
    }
};