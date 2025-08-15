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
    execv("/sbin/agetty", args);
}