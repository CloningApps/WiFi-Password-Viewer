#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>
#include "view.h"

int android_mode = 0;
int no_root_mode = 0;

int main(int argc, char *argv[]) {
    const char *nm_dir = "/etc/NetworkManager/system-connections/";
    const char *android_dir = "/data/misc/wifi/";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--android") == 0) {
            android_mode = 1;
        } else if (strcmp(argv[i], "--no-root") == 0) {
            no_root_mode = 1;
        }
    }

    if (!no_root_mode && geteuid() != 0) {
        printf("This program requires root privileges. Please run with sudo or use --no-root.\n");
        return 1;
    }

    printf("WiFi Passwords:\n");
    printf("---\n");

    if (android_mode) {
        process_directory(android_dir);
    } else {
        process_directory(nm_dir);
    }

    return 0;
}

