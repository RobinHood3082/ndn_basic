cmake_minimum_required(VERSION 3.21)
project(ndn_basic)

set(CMAKE_CXX_STANDARD 17)

add_library(ndn_basic library.cpp devices/node.cpp devices/node.h packets/Packet.cpp packets/Packet.h packets/Interest.cpp packets/Interest.h packets/Data.cpp packets/Data.h components/ContentStore.cpp components/ContentStore.h components/PendingInterestTable.cpp components/PendingInterestTable.h components/ForwardingInformationBase.cpp components/ForwardingInformationBase.h)
