#include "Utils.hpp"

namespace HInit {
    inline char* systemd_udevd_args[] = {"/lib/systemd/systemd-udevd"};
    inline char* udevadm_trigger_args[] = {"udevadm", "trigger"};
    inline char* udevadm_settle_args[] = {"udevadm", "settle"};
    void SetupUdevd() {
        Utils::RunCommand(systemd_udevd_args[0], systemd_udevd_args);
        Utils::RunCommand(udevadm_trigger_args[0], udevadm_trigger_args);
        Utils::RunCommand(udevadm_settle_args[0], udevadm_settle_args);
    }
}