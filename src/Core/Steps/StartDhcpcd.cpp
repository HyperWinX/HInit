#include "Utils.hpp"

namespace HInit {
    inline char* dhcpcd_args[] = {"/sbin/dhcpcd", "-q"};
    void StartDhcpcd() {
        Utils::RunCommand<Utils::RunMode::Background>(dhcpcd_args[0], dhcpcd_args);
    }
}