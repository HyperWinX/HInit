#include "Utils.hpp"

namespace HInit {
    inline char* fsck_args[] = {"fsck", ""};
    inline char* root_remount_args[] = {"mount", "/", "-o", "remount,rw"};
    inline char* all_mount_args[] = {"mount", "-a"};
    void MountAll() {
        Utils::RunCommand("fsck", fsck_args);
        Utils::RunCommand("mount", root_remount_args);
        Utils::RunCommand("mount", all_mount_args);
    }
}