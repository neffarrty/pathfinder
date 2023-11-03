#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "libmx.h"

#define INF INT_MAX

typedef struct s_bridge {
    char* left;
    char* right;
    int distance;
} 			   t_bridge;

typedef enum e_error {
	INVALID_ARGS,
	INVALID_FILE,
	EMPTY_FILE,
	INVALID_FIRST_LINE,
	INVALID_LINE,
	INVALID_NUM_OF_ISLANDS,
	DUPLICATE_BRIDGES,
	INVALID_SUM_OF_BRIDGES
}			t_error;

void mx_pathfinder(const char* filename);

void mx_check_file(const char* filename);

int mx_create_bridges_arr(char** lines, t_bridge** bridges, int size);

char** mx_create_islands_arr(t_bridge** bridges, int bridges_size, int islands_size);

t_bridge* mx_parse_line(char* line, int line_num);

int **mx_create_adjacency_matrix(t_bridge** bridges, int bridges_size, char** islands, int size);

void mx_handle_err(int type, void* param);

bool mx_check_island(const char* s);

void mx_check_duplicates(t_bridge** bridges, int size);

void mx_check_invalid_sum(t_bridge** bridges, int size);

int mx_array_index_of(char** arr, const char* key);

int** mx_floyd_warshall(int** matrix, int size);

void mx_print_path(int* path, int size, int** matrix, char** islands);

void mx_print_all_pathes(int **adj_matrix, int **dist_matrix, int size, char **islands, int *path, int path_size);

void mx_del_array(void* arr);

void mx_del_matrix(int** matrix, int size);

void mx_del_bridges_arr(t_bridge** bridges, int size);

#endif


