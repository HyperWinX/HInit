#include <cstdlib>

#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

int main() {
    std::cout << "Starting up udevd...\n";
    system("/lib/systemd/systemd-udevd &> /dev/null &");
    std::cout << "Mounting all volumes...\n";
    system("mount -a");
    /* Late startup */
    static char* args[] = {
        "/sbin/agetty",
        "-o",
        "-- \\u",
        "--noreset",
        "--noclear",
        "-",
        "xterm",
        "linux",
        NULL
    };
    while (1) {
        pid_t agetty = fork();
        if (agetty == 0) {
            execv("/sbin/agetty", args);
            std::exit(1);
        }
        int status;
        waitpid(agetty, &status, 0);
    }
}