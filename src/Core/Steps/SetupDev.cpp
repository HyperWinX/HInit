#include "Utils.hpp"

namespace HInit {
    inline char* fd_args[] = {"ln", "-sf", "/proc/self/fd", "/dev/fd"};
    inline char* stdin_args[] = {"ln", "-sf", "/proc/self/fd/0", "/dev/stdin"};
    inline char* stdout_args[] = {"ln", "-sf", "/proc/self/fd/1", "/dev/stdout"};
    inline char* stderr_args[] = {"ln", "-sf", "/proc/self/fd/2", "/dev/stderr"};
    void SetupDev() {
        Utils::RunCommand(fd_args[0], fd_args);
        Utils::RunCommand(stdin_args[0], stdin_args);
        Utils::RunCommand(stdout_args[0], stdout_args);
        Utils::RunCommand(stderr_args[0], stderr_args);
    }
}