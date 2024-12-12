#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_LINE 256

void trim(char *str) {
    char *end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0) return;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

void get_wifi_password(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_path);
        return;
    }

    char line[MAX_LINE];
    char ssid[MAX_LINE] = "";
    char psk[MAX_LINE] = "";

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "ssid=", 5) == 0) {
            strncpy(ssid, line + 5, sizeof(ssid) - 1);
            trim(ssid);
        } else if (strncmp(line, "psk=", 4) == 0) {
            strncpy(psk, line + 4, sizeof(psk) - 1);
            trim(psk);
        }
    }

    fclose(file);

    if (strlen(ssid) > 0 && strlen(psk) > 0) {
        printf("Network: %s\n", ssid);
        printf("Password: %s\n", psk);
        printf("---\n");
    }
}

int main() {
    if (geteuid() != 0) {
        printf("This program requires root privileges. Please run with sudo.\n");
        return 1;
    }

    const char *nm_dir = "/etc/NetworkManager/system-connections/";
    DIR *dir;
    struct dirent *ent;

    dir = opendir(nm_dir);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", nm_dir);
        return 1;
    }

    printf("WiFi Passwords:\n");
    printf("---\n");

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s%s", nm_dir, ent->d_name);
            get_wifi_password(file_path);
        }
    }

    closedir(dir);
    return 0;
}
