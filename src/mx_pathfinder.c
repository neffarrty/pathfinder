#include "pathfinder.h"

void mx_pathfinder(const char* filename) {
    int bridges_size = 0;
    int islands_size = 0;
    int **adjacency_matrix = NULL;
    int **distances_matrix = NULL;
    char *file_str = NULL;
    char **lines = NULL;
    char **islands = NULL;
    t_bridge **bridges = NULL;

    mx_check_file(filename);

    file_str = mx_file_to_str(filename);
    lines = mx_strsplit(file_str, '\n');
    for(int i = 1; lines[i]; i++) {
        bridges_size++;
    }
    bridges = (t_bridge**)malloc(bridges_size * sizeof(t_bridge*));

    islands_size = mx_create_bridges_arr(lines, bridges, bridges_size);

    mx_check_duplicates(bridges, bridges_size);
    mx_check_invalid_sum(bridges, bridges_size);

    islands = mx_create_islands_arr(bridges, bridges_size, islands_size);

    adjacency_matrix = mx_create_adjacency_matrix(bridges, bridges_size, islands, islands_size);

    distances_matrix = mx_floyd_warshall(adjacency_matrix, islands_size);

    int *path = (int*)malloc((islands_size + 1) * sizeof(int));
    int path_size = 1;

    for (int i = 0; i < islands_size; i++) {
        for (int j = i + 1; j < islands_size; j++) {
            path[1] = i;
            path[0] = j;
            mx_print_all_pathes(adjacency_matrix, distances_matrix, islands_size, islands, path, path_size);
        }
    }

    mx_del_array(file_str);
    mx_del_array(path);
    mx_del_matrix(adjacency_matrix, islands_size);
    mx_del_matrix(distances_matrix, islands_size);
    mx_del_strarr(&lines);
    mx_del_strarr(&islands);
    mx_del_bridges_arr(bridges, bridges_size);
}


