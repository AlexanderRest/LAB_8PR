#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#define MAX_STRING_LEN 32

typedef struct {
    int port;
    const char *socket_type;
} Config;

Config parse_config(const char *filename);

#endif
