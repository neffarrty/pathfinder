#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "../libmx/inc/libmx.h"

#define INFINITY INT_MAX

typedef struct s_bridge {
    char* left;
    char* right;
    int cost;
} t_bridge;

int mx_read_file(const char* filename, t_list** bridges);

t_list* mx_create_islands_list(t_list* bridges);

bool mx_is_valid_island(const char* s);

t_bridge* mx_parse_line(char* line);

int **mx_create_adjacency_matrix(t_list* bridges, t_list* islands);

enum e_error {
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

bool mx_list_has_bridge(t_list* list, t_bridge* key);

bool mx_check_duplicates(t_list* list);

bool check_invalid_sum(t_list* list);

int mx_list_index_of(t_list* list, const char* key);

char* mx_list_get_by_index(t_list* list, int i);

void mx_pathfinder(const char* filename);

void mx_dijkstra(int** adj_matrix, int size, int start, t_list* islands);

void mx_print_path(int start, int end, t_list* route, t_list* islands, int** matrix);

#endif


