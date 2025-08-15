#include <cstdlib>

#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

int main() {
    std::cout << "Mounting all volumes...\n";
    system("fsck");
    system("mount / -o remount,rw &> /dev/null");
    system("mount -a &> /dev/null");
    std::cout << "Setting up /dev...\n";
    system("ln -sf /proc/self/fd /dev/fd");
    system("ln -sf /proc/self/fd/0 /dev/stdin");
    system("ln -sf /proc/self/fd/1 /dev/stdout");
    system("ln -sf /proc/self/fd/2 /dev/stderr");
    std::cout << "Starting up udevd...\n";
    system("/lib/systemd/systemd-udevd &> /dev/null &");
    system("udevadm trigger &> /dev/null");
    system("udevadm settle &> /dev/null");
    std::cout << "Starting up dhcpcd...\n";
    system("/sbin/dhcpcd -q &");

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