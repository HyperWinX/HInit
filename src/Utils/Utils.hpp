#include <string>

#include <sys/wait.h>
#include <unistd.h>

namespace HInit::Utils {
    enum class RunMode {
        Wait,
        Background
    };

    template<RunMode Md = RunMode::Wait>
    inline int RunCommand(const char* command, char* const* args) {
        pid_t child = fork();
        if (child == 0) {
            execv(command, args);
            std::exit(1);
        }
        if constexpr (Md == RunMode::Wait) {
            int status;
            waitpid(child, &status, 0);
            return status;
        } else {
            return 0;
        }
    }
}