cmake_minimum_required(VERSION 3.21)
project(ndn_basic)

set(CMAKE_CXX_STANDARD 17)

add_library(ndn_basic library.cpp cmake-build-debug/devices/node.cpp cmake-build-debug/devices/node.h cmake-build-debug/packets/Packet.cpp cmake-build-debug/packets/Packet.h cmake-build-debug/packets/Interest.cpp cmake-build-debug/packets/Interest.h cmake-build-debug/packets/Data.cpp cmake-build-debug/packets/Data.h cmake-build-debug/components/ContentStore.cpp cmake-build-debug/components/ContentStore.h)
