#include <string>

#include <sys/wait.h>
#include <unistd.h>

namespace HInit::Utils {
    inline int RunCommand(const char* command, char* const* args) {
        pid_t child = fork();
        if (child == 0) {
            execv(command, args);
        }
        int status;
        waitpid(child, &status, 0);
        return status;
    }
}