#include <cstdlib>

#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

#include "spdlog/spdlog.h"

#include "Steps.hpp"

int main() {
    spdlog::set_pattern("[*] %v");

    spdlog::info("Mounting all volumes");
    HInit::MountAll();

    spdlog::info("Setting up /dev");
    HInit::SetupDev();

    spdlog::info("Starting up udevd");
    HInit::SetupUdevd();

    spdlog::info("Starting up dhcpcd");
    HInit::StartDhcpcd();

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