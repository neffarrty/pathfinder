#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "../libmx/inc/libmx.h"

int mx_file_size(int fd);
void mx_printerr(const char* s);

//TO LIBMX
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isalpha(int c);

typedef struct s_bridge {
    char* left;
    char* right;
    int cost;
} t_bridge;

void read_file(const char* filename);
t_bridge *mx_split_line(char* line);

enum {
	INVALID_ARGS,
	INVALID_FILE,
	EMPTY_FILE,
	INVALID_FIRST_LINE,
	INVALID_LINE,
	INVALID_NUM_OF_ISLANDS,
	DUPLICATE_BRIDGES,
	INVALID_SUM_OF_BRIDGES
};

void mx_handle_err(int err_type, void* param);

#endif


