#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libmysyslog.h"

int mysyslog(const char* msg, int level, int driver, const char* path) {
    if (msg == NULL || path == NULL) {
        return -1;
    }

    FILE *log_file = fopen(path, "a");
    if (log_file == NULL) {
        return -1;
    }

    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    if (timestamp != NULL) {
        timestamp[strlen(timestamp) - 1] = '\0';

    const char *level_str;
    switch (level) {
        case DEBUG:    level_str = "DEBUG"; break;
        case INFO:     level_str = "INFO"; break;
        case WARN:     level_str = "WARN"; break;
        case ERROR:    level_str = "ERROR"; break;
        case CRITICAL: level_str = "CRITICAL"; break;
        default:       level_str = "UNKNOWN"; break;
    }

    if (timestamp != NULL) {
        fprintf(log_file, "%s %s %d %s\n", timestamp, level_str, driver, msg);
    } else {
        fprintf(log_file, "NULL %s %d %s\n", level_str, driver, msg);
    }

    fclose(log_file);
    return 0;
}
