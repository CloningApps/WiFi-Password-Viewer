#ifndef WIFI_PASSWORD_H
#define WIFI_PASSWORD_H

#define MAX_PATH 1024
#define MAX_LINE 256

void trim(char *str);
void get_wifi_password(const char *file_path);
void process_directory(const char *dir_path);

#endif // WIFI_PASSWORD_H

