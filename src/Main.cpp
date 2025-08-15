#include <cstdlib>

#include <unistd.h>

int main() {
    static char* args[] = {
        "-o",
        "'-- \\\\u'",
        "--noreset",
        "--noclear",
        "-",
        "xterm"
    };
    pid_t agetty = fork();
    if (agetty == 0) {
        execv("/sbin/agetty", args);
        std::exit(1);
    }
    for (;;);
}