//
// Created by rkhan on 09/03/2022.
//

#ifndef NDN_BASIC_FORWARDINGINFORMATIONBASE_H
#define NDN_BASIC_FORWARDINGINFORMATIONBASE_H

namespace ndn {
    class ForwardingInformationBase {
	std::unordered_map <std::string, std::vector <std::string>> fibTable;
    };
}

#endif //NDN_BASIC_FORWARDINGINFORMATIONBASE_H
